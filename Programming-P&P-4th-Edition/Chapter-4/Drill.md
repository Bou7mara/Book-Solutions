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
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}
```

---

#### 1. Fragment 1
* **Original:** `Cout << "Success!\n";`
* **Error:** C++ is case-sensitive; `Cout` is undefined.
* **Correction:**
  ```cpp
  cout << "Success!\n";
  ```

#### 2. Fragment 2
* **Original:** `cout << "Success!\n;`
* **Error:** Missing closing double-quote `"` for the string literal.
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
* **Error:** `success` is treated as an undeclared variable name rather than a string literal.
* **Correction:**
  ```cpp
  cout << "Success" << '\n';
  ```

#### 5. Fragment 5
* **Original:** `string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";`
* **Error:** Cannot assign integer `7` to `std::string` or assign `res` (a string) to `v[5]` (an integer vector).
* **Correction:**
  ```cpp
  int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
  ```

#### 6. Fragment 6
* **Original:** `vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n";`
* **Error:** Vector indexing uses `[]` not `()`, and the condition `!= 7` is inverted.
* **Correction:**
  ```cpp
  vector<int> v(10); v[5] = 7; if (v[5] == 7) cout << "Success!\n";
  ```

#### 7. Fragment 7
* **Original:** `if (cond) cout << "Success!\n"; else cout << "Fail!\n";`
* **Error:** `cond` is an undeclared variable.
* **Correction:**
  ```cpp
  bool cond = true; if (cond) cout << "Success!\n"; else cout << "Fail!\n";
  ```

#### 8. Fragment 8
* **Original:** `bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";`
* **Error:** `c` is initialized to `false`, causing the `else` branch ("Fail!\n") to execute.
* **Correction:**
  ```cpp
  bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";
  ```

#### 9. Fragment 9
* **Original:** `string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";`
* **Error:** Typo `boo` instead of `bool`, and `"fool" < s` evaluates to `false`.
* **Correction:**
  ```cpp
  string s = "ape"; bool c = "fool" > s; if (c) cout << "Success!\n";
  ```

#### 10. Fragment 10
* **Original:** `string s = "ape"; if (s=="fool") cout << "Success!\n";`
* **Error:** Condition `"ape" == "fool"` is `false`.
* **Correction:**
  ```cpp
  string s = "ape"; if (s != "fool") cout << "Success!\n";
  ```

#### 11. Fragment 11
* **Original:** `string s = "ape"; if (s=="fool") cout < "Success!\n";`
* **Error:** Stream operator `<` is wrong (should be `<<`), and condition `s == "fool"` is `false`.
* **Correction:**
  ```cpp
  string s = "ape"; if (s != "fool") cout << "Success!\n";
  ```

#### 12. Fragment 12
* **Original:** `string s = "ape"; if (s+"fool") cout < "Success!\n";`
* **Error:** String concatenation `s + "fool"` cannot be used as a boolean expression, and `<` operator is incorrect.
* **Correction:**
  ```cpp
  string s = "ape"; if (s + "fool" == "apefool") cout << "Success!\n";
  ```

#### 13. Fragment 13
* **Original:** `vector<char> v(5); for (int i = 0; 0<v.size(); ++i) ; cout << "Success!\n";`
* **Error:** The condition `0 < v.size()` creates an infinite loop.
* **Correction:**
  ```cpp
  vector<char> v(5); for (int i = 0; i < v.size(); ++i) ; cout << "Success!\n";
  ```

#### 14. Fragment 14
* **Original:** `vector<char> v(5); for (int i = 0; i<=v.size(); ++i) ; cout << "Success!\n";`
* **Error:** Loop condition `i <= v.size()` goes out of bounds (iterates 6 times for size 5).
* **Correction:**
  ```cpp
  vector<char> v(5); for (int i = 0; i < v.size(); ++i) ; cout << "Success!\n";
  ```

#### 15. Fragment 15
* **Original:** `string s = "Success!\n"; for (int i = 0; i<6; ++i) cout << s[i];`
* **Error:** Loop condition `i < 6` terminates early, outputting only `"Succes"`.
* **Correction:**
  ```cpp
  string s = "Success!\n"; for (int i = 0; i < s.size(); ++i) cout << s[i];
  ```

#### 16. Fragment 16
* **Original:** `if (true) then cout << "Success!\n"; else cout << "Fail!\n";`
* **Error:** `then` is not a valid C++ keyword.
* **Correction:**
  ```cpp
  if (true) cout << "Success!\n"; else cout << "Fail!\n";
  ```

#### 17. Fragment 17
* **Original:** `int x = 2000; char c = x; if (c==2000) cout << "Success!\n";`
* **Error:** Assigning `2000` to an 8-bit `char` causes narrowing/overflow, so `c == 2000` evaluates to `false`.
* **Correction:**
  ```cpp
  int x = 2000; int c = x; if (c == 2000) cout << "Success!\n";
  ```

#### 18. Fragment 18
* **Original:** `string s = "Success!\n"; for (int i = 0; i<10; ++i) cout << s[i];`
* **Error:** `"Success!\n"` is length 9; `i < 10` accesses `s[9]` out-of-bounds.
* **Correction:**
  ```cpp
  string s = "Success!\n"; for (int i = 0; i < s.size(); ++i) cout << s[i];
  ```

#### 19. Fragment 19
* **Original:** `vector v(5); for (int i = 0; i<=v.size(); ++i) ; cout << "Success!\n";`
* **Error:** Missing template argument for `vector` and `<= ` causes an out-of-bounds iteration.
* **Correction:**
  ```cpp
  vector<int> v(5); for (int i = 0; i < v.size(); ++i) ; cout << "Success!\n";
  ```

#### 20. Fragment 20
* **Original:** `int i = 0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";`
* **Error:** Infinite loop because `i` is never incremented inside the `while` loop.
* **Correction:**
  ```cpp
  int i = 0; int j = 9; while (i < 10) ++i; if (j < i) cout << "Success!\n";
  ```

#### 21. Fragment 21
* **Original:** `int x = 2; double d = 5/(x-2); if (d==2*x+0.5) cout << "Success!\n";`
* **Error:** Division by zero (`x - 2 = 0`), integer truncation, and arithmetic mismatch.
* **Correction:**
  ```cpp
  int x = 2; double d = 2 * x + 0.5; if (d == 2 * x + 0.5) cout << "Success!\n";
  ```

#### 22. Fragment 22
* **Original:** `string<char> s = "Success!\n"; for (int i = 0; i<=10; ++i) cout << s[i];`
* **Error:** `string<char>` is invalid syntax, and `i <= 10` accesses elements out-of-bounds.
* **Correction:**
  ```cpp
  string s = "Success!\n"; for (int i = 0; i < s.size(); ++i) cout << s[i];
  ```

#### 23. Fragment 23
* **Original:** `int i = 0; while (i<10) ++j; if (j<i) cout << "Success!\n";`
* **Error:** `j` is undeclared, and `i` is never incremented (infinite loop).
* **Correction:**
  ```cpp
  int i = 0; int j = 9; while (i < 10) ++i; if (j < i) cout << "Success!\n";
  ```

#### 24. Fragment 24
* **Original:** `int x = 4; double d = 5/(x-2); if (d==2*x+0.5) cout << "Success!\n";`
* **Error:** Integer division `5 / 2` truncates to `2`, so `d` (2.0) does not equal `8.5`.
* **Correction:**
  ```cpp
  int x = 4; double d = 5.0 / (x - 2) + 6.0; if (d == 2 * x + 0.5) cout << "Success!\n";
  ```

#### 25. Fragment 25
* **Original:** `cin << "Success!\n";`
* **Error:** `cin` is standard input and cannot use output insertion `<<`.
* **Correction:**
  ```cpp
  cout << "Success!\n";
  ```
