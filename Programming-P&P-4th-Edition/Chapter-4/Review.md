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

