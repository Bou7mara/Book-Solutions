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
