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

### [15] When is returning an "error value" preferable to throwing an exception?

### [16] Describe the process of how exceptions are thrown and caught.

### [17] Why, with a vector called `v`, is `v[v.size()]` a range error? What would be the result of calling this?

### [18] What is an assertion?

### [19] Define *precondition* and *postcondition*; give an example (that is not the `area()` function from this chapter), preferably a computation that requires a loop.

### [20] When would you *not* test a precondition?

### [21] When would you *not* test a postcondition?

### [22] What are the steps in debugging a program?

### [23] Why does commenting help when debugging?

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
