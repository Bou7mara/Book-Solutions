# Programming: Principles and Practice Using C++ (PPP)
## Chapter 4 Drill Solutions

### Scaffolding
```cpp
#include "PPP.h"

int main()
try {
    <<your code here>>
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\\n';
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\\n";
    return 2;
}
```
---

#### 1. Fragment 1
* **Original:** `Cout << "Success!\n";`
* **Error:** C++ is case-sensitive; `Cout` is undefined. It must be `cout`.
* **Correction:**
  ```cpp
  cout << "Success!\n";
  ```

#### 2. Fragment 2
* **Original:** `cout << "Success!\n;`
* **Error:** Missing closing double quotation mark `"` for the string literal.
* **Correction:**
  ```cpp
  cout << "Success!\n";
  ```

#### 3. Fragment 3
* **Original:** `cout << "Success" << !\n"`
* **Error:** Missing semicolon `;` at the end and malformed string literal `!\n"`.
* **Correction:**
  ```cpp
  cout << "Success" << "!\n";
  ```

#### 4. Fragment 4
* **Original:** `cout << success << '\n';`
* **Error:** `success` is treated as an undeclared identifier/variable rather than a string literal.
* **Correction:**
  ```cpp
  cout << "Success" << '\n';
  ```

#### 5. Fragment 5
* **Original:** `string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";`
* **Error:** 
  1. Cannot assign an integer literal `7` directly to `std::string`.
  2. Type mismatch when assigning `res` (a `string`) to `v[5]` (which holds `int`).
* **Correction:**
  ```cpp
  int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
  ```

#### 6. Fragment 6
* **Original:** `vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n";`
* **Error:**
  1. Vector elements are accessed using square brackets `[]`, not function call parentheses `()`.
  2. The logical comparison `!= 7` is inverted; since `v[5]` was set to `7`, checking `!= 7` evaluates to false and suppresses output.
* **Correction:**
  ```cpp
  vector<int> v(10); v[5] = 7; if (v[5] == 7) cout << "Success!\n";
  ```
