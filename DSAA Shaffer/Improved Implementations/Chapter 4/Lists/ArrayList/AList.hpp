#pragma once
#include "List.hpp"
#include <stdexcept>
#include <type_traits>
#include <utility>
#include <vector>

namespace improved {

// Like the original interface, this is a copy-oriented container. E's gotta be
// copy-constructible and assignable from an rvalue. E doesnt have to have a default constructor
template <class E>
class AList final : public List<E> {
    static_assert(std::is_copy_constructible_v<E>,
                  "AList requires copy-constructible elements");
    static_assert(std::is_move_assignable_v<E>,
                  "AList requires elements assignable from an rvalue");

public:
    using size_type = typename List<E>::size_type;
    static constexpr size_type default_capacity = 100;

    // explicit prevents accidental conversion from an integer to a list.
    explicit AList(size_type capacity = default_capacity) : capacity_(capacity) {
        // reserve allocates storage; it does NOT construct capacity E objects.
        // capacity_ is the logical limit even if vector reserves extra storage.
        elements_.reserve(capacity_);
    }

    ~AList() override = default; // vector releases storage automatically (RAII).

    // Deliberate value semantics for the concrete class. We initialize the base
    // with its default constructor, so its deleted copying is not invoked.
    AList(const AList& other) : AList(other.capacity_) {
        for (const auto& value : other.elements_) {
            elements_.push_back(value);
        }
        cursor_ = other.cursor_;
    }

    AList& operator=(const AList& other) {
        if (this != &other) {
            AList copy(other); // If copying throws, *this is unchanged.
            swap(copy);
        }
        return *this; // Conventional assignment returns a reference, not void.
    }

    AList(AList&& other) noexcept
        : capacity_(other.capacity_), cursor_(other.cursor_),
          elements_(std::move(other.elements_)) {
        // Do not rely on an unspecified moved-from vector size. A moved-from
        // AList is empty, at position 0, with logical capacity 0.
        other.elements_.clear();
        other.capacity_ = 0;
        other.cursor_ = 0;
    }

    AList& operator=(AList&& other) noexcept {
        if (this != &other) {
            AList moved(std::move(other));
            swap(moved); // moved destroys our former elements and storage.
        }
        return *this;
    }

    void swap(AList& other) noexcept {
        using std::swap;
        swap(capacity_, other.capacity_);
        swap(cursor_, other.cursor_);
        elements_.swap(other.elements_);
    }

    friend void swap(AList& left, AList& right) noexcept { left.swap(right); }

    void clear() override {
        elements_.clear(); // Destroys active elements; retains allocated storage.
        cursor_ = 0;
    }

    void insert(const E& value) override {
        require_space();
        // value may refer to an element of THIS list. Save it before shifting.
        E saved(value);
        const auto old_size = elements_.size();
        if (cursor_ == old_size) {
            elements_.push_back(saved); // Inserting at end is valid.
            return;
        }

        // Copy the last element into a new live slot, then shift right.
        // Storage was reserved at construction, so no reallocation occurs.
        elements_.push_back(elements_.back());
        try {
            for (auto i = old_size - 1; i > cursor_; --i) {
                elements_[i] = std::move(elements_[i - 1]);
            }
            elements_[cursor_] = std::move(saved);
        } catch (...) {
            // Restore length and structural invariants, but earlier assignments
            // may already have changed values. See README's exception limits.
            elements_.pop_back();
            throw;
        }
        // Cursor stays at the insertion position, now naming the new element.
    }

    void append(const E& value) override {
        require_space();
        // No shifts and no reallocation: push_back safely copies even when
        // value aliases an existing element. Cursor's numeric position stays.
        elements_.push_back(value);
    }

    E remove() override {
        require_current();
        E removed(elements_[cursor_]); // Copy before making any changes.
        for (auto i = cursor_; i + 1 < elements_.size(); ++i) {
            elements_[i] = std::move(elements_[i + 1]);
        }
        elements_.pop_back();
        // If the last element was removed, cursor_ is now the end position.
        return removed; // Usually elided; a throwing return move/copy can occur.
    }

    void moveToStart() override { cursor_ = 0; }
    void moveToEnd() override { cursor_ = elements_.size(); }
    void prev() override { if (cursor_ > 0) --cursor_; }
    void next() override { if (cursor_ < elements_.size()) ++cursor_; }

    [[nodiscard]] size_type length() const override { return elements_.size(); }
    [[nodiscard]] size_type currPos() const override { return cursor_; }
    [[nodiscard]] size_type capacity() const noexcept { return capacity_; }

    void moveToPos(size_type position) override {
        if (position > elements_.size()) {
            throw std::out_of_range("AList: cursor must be in [0, length]");
        }
        cursor_ = position;
    }

    [[nodiscard]] const E& getValue() const override {
        require_current();
        return elements_[cursor_]; // Reference avoids copying; read-only access.
    }

private:
    // Invariants: size <= capacity_, cursor_ <= size, allocated vector capacity
    // >= capacity_. elements_.size() replaces the redundant listSize counter.
    size_type capacity_ = 0;
    size_type cursor_ = 0;
    std::vector<E> elements_;

    void require_space() const {
        if (elements_.size() == capacity_) {
            throw std::length_error("AList: fixed logical capacity reached");
        }
    }

    void require_current() const {
        if (cursor_ == elements_.size()) {
            throw std::out_of_range("AList: end cursor has no current element");
        }
    }
};

}
