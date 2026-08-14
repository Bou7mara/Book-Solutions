# Programming: Principles and Practice Using C++ (PPP)
## Chapter 5 Drill Solutions

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
