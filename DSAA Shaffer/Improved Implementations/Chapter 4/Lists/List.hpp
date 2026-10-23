#pragma once
#include <cstddef>
namespace improved {

template <class E>
class List {
public:
    using size_type = std::size_t;

    List() = default;
    // '= delete' states the intent clearly. The textbook's private, undefined
    // copy operations often defer a mistake to a less helpful linker error.
    List(const List&) = delete;
    List& operator=(const List&) = delete;
    List(List&&) = delete;
    List& operator=(List&&) = delete;

    // Destruction through List<E>* is safe. No handwritten empty body needed.
    virtual ~List() = default;

    virtual void clear() = 0;
    virtual void insert(const E& value) = 0;
    virtual void append(const E& value) = 0;
    virtual E remove() = 0;
    virtual void moveToStart() = 0;
    virtual void moveToEnd() = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    [[nodiscard]] virtual size_type length() const = 0;
    [[nodiscard]] virtual size_type currPos() const = 0;
    virtual void moveToPos(size_type position) = 0;
    [[nodiscard]] virtual const E& getValue() const = 0;
};

}
