# Programming: Principles and Practice Using C++ (PPP)
## Chapter 4 Review Solutions

### [1] Name four major types of errors and briefly define each one.
* **Compile-time errors:** Errors found by the compiler: syntax and type errors...
* **Link-time errors:** Errors found by the linker when combining object files and libraries: function/symbol definitions...
* **Run-time errors:** Errors found while the program is running: division by zero, out-of-bounds access, hardware exceptions...
* **Logic errors:** Errors caused by flawed logic where the code runs without crashing but produces incorrect results.

### [2] What kinds of errors can we ignore in student programs?
* Hardware failing, operating-system crashing, out of memory states...

### [3] What guarantees should every completed project offer?
I guess, most importantly, correctness; a program should produce correct results for all legal inputs. It should also give adequate error messages in the case of illegal input, or otherwise fail predictably.

### [4] List three approaches we can take to eliminate errors in programs and produce acceptable software.
I feel like I was reaching with these answers, so take this with a grain of salt.
* **Organize the code:** Structuring the code in a way that isn't error prone, although terrible for job security ;), makes it significantly harder for bugs to hide in code. This involves good documentation, comments, and small functions that perform one logical task.
* **Debugging and testing:** Through trial and error, one can eliminate most bugs in their software.
* **Assertions:** Embedding run-time checks within the code will help locate errors.

### [5] Why do we hate debugging.
Who's "we", I don't. However, it is annoying, time-consuming, tedious...

### [6] What is a syntax error? Give five examples.
* **Definition:** A violation of the grammar rules of the programming language detected by the compiler.
* **Examples:** Missing semicolon, mismatched parentheses, misspelled keyword, incorrect capitalization, wrong operator usage.

### [7] What is a type error? Give five examples.
* **Definition:** An operation performed on data types that are incompatible or invalid without proper conversion.
I don't know what I'm doing wrong here cause my answer will be redundant, something like: Assigning a string to an int, assigning an int to a string, passing the wrong argument type to a function and so on...

### [8] What is a linker error? Give three examples
* **Definition:** An error that occurs when the linker cannot combine multiple translation units into one executable source file.
* **Examples:** Missing definition, double definition and definition mismatch between declaration and definition.

### [9] What is a logic error? Give three examples.
* **Definition:** An error that occurs when the code executes successfully but yields incorrect results because the programmer ain't shit.
* **Examples:** Yeah no I'm not giving 3 examples... when your for loop is off by one.

### [10] List four potential sources of program errors discussed in the text.
  * Misunderstanding program requirements.
  * Bad user input.
  * Unhandled edge cases
  * Programmer mistakes, including typos, stupid errors, or wrong assumptions about a library function.

### [11] How do you know if a result is plausible? What techniques do you have to answer such questions?
  * Asking myself if an answer makes sense (a father can't be younger than his child...)
  * Drafting estimations on the side
  * Assertions for sanity checks.
  * Manually checking output against simple test cases.

### [12] How do you test if an input operation succeeded?
  * You check the status of the input stream right after reading into a variable, usually using an if statement like if (cin >> x). If it evaluates to true, the read worked; if false, invalid data or an end-of-file was reached.

### [13] Compare and contrast having the caller of a function handle a run-time error vs. having the called function handle the run-time error.
* **Caller handles it:** The function signals an error back to the caller (e.g., via return value or exception). This lets the caller decide what to do using the bigger picture of the application, though it can make calling code cluttered if every call requires checks.
* **Called function handles it:** The function fixes or stops the program itself. This keeps caller code clean, but the function often lacks the broader context to make the right call for the whole application.

### [14] When is throwing an exception preferable to returning an "error value"?
* When returning an error code would ruin the function's return type or interfere with valid return values.
* When the error needs to be handled multiple levels up the call stack rather than right away.
* When an error happens inside a class constructor, which cannot return a value.

### [15] When is returning an "error value" preferable to throwing an exception?
* When an error is an expected, common event during normal use (like hitting the end of a file).
* In fast, inner loops where the overhead of throwing an exception would slow things down.
* When writing or interfacing with simple C-style code where exceptions aren't supported.

### [16] Describe the process of how exceptions are thrown and caught.
1. **Throwing:** Code detects a problem it can't handle and calls `throw` with an error object.
2. **Unwinding:** The program pauses current work and travels back up through calling functions searching for a matching `try/catch` block, cleaning up local variables on the way back.
3. **Catching:** Execution jumps into the matching `catch` block to deal with the problem.

### [17] Why, with a vector called `v`, is `v[v.size()]` a range error? What would be the result of calling this?
* **Why:** Vectors use zero-based indexing, meaning valid positions go from `0` to `v.size() - 1`. The index `v.size()` points to the position just after the last element, which doesn't exist.
* **Result:** Using `v[v.size()]` tries to read memory outside the vector, causing unpredictable behavior (or throwing an exception if accessed via `.at()`).

### [18] What is an assertion?
* An explicit check in your code stating "this condition must be true right here". If the check fails, the program immediately halts and prints an error message to alert you during development.

### [19] Define *precondition* and *postcondition*; give an example (that is not the `area()` function from this chapter), preferably a computation that requires a loop.
* **Precondition:** What must be true *before* a function runs for it to work correctly.
* **Postcondition:** What the function promises will be true *after* it finishes running.
* **Example:**
  ```cpp
  // Precondition: v is not empty; target exists in range.
  // Postcondition: Returns index 'i' such that v[i] == target, or -1 if not found.
  int find_first_index(const std::vector<int>& v, int target) {
      if (v.empty()) return -1;

      for (int i = 0; i < v.size(); ++i) {
          if (v[i] == target) return i;
      }
      return -1;
  }
  ```

### [20] When would you *not* test a precondition?
* When checking it takes too much time or computing power (e.g., checking if a list is sorted before running a binary search).
* In small helper functions where the calling function already checked the inputs.
* In performance-critical loops where every microsecond matters and you know the input is already safe.

### [21] When would you *not* test a postcondition?
* When verifying the result requires repeating the entire calculation, doubling the work.
* When the outcome is already obvious or guaranteed by the compiler and language rules.

### [22] What are the steps in debugging a program?
1. **Reproduce:** Find a clear, repeatable set of steps that triggers the bug.
2. **Isolate:** Narrow down the exact lines of code causing the issue.
3. **Understand:** Figure out why the code is behaving differently than expected.
4. **Fix & Test:** Apply a fix and run tests to make sure you solved the bug without creating new ones.

### [23] Why does commenting help when debugging?
* Temporarily commenting out chunks of code lets you test parts of your program in isolation to locate where things break.
* Explaining what your code is supposed to do in comments forces you to rethink the logic, making mistakes easier to spot.
### [24] How does testing differ from debugging?
* Debugging is locating, diagnosing and fixing the errors, while testing is executing code with different inputs to verify how correct the code is. I guess testing helps us figure out if the code as a whole works correctly with a certain input, which then lets us know that there is (or isn't) an error somewhere
  
### [25] What is a random number?
* In computer science, a random number is a value generated by a deterministic algorithm that mimics the statistical properties of randomness.

### [26] How do we use `random_int()` and `seed()`?
| Function | Purpose | Example |
| :--- | :--- | :--- |
| **`rand_int(low, high)`** | Returns a random integer between `low` and `high` (inclusive) [1]. | `rand_int(1, 6)` |
| **`seed(n)`** | Seeds the random engine with a specific integer `n` to produce a repeatable sequence [1]. | `seed(42)` |
| **`seed()`** | Seeds the random engine with an unpredictable value (like the current time) for unique results each run [1]. | `seed()` |
