# OOP_Cplusplus
CONTAIN SOME PRACTICING EX C++

And some useful questions:
## 1. GET RESULT FROM A THREAD
``` c
#include <iostream>
#include <thread>
using namespace std;

int ret4(){ return 4; }
int ret6(){ return 6; }

int main() {
    int r1;
    int r2;
    // using lambda and capture ref local var
    thread t1( [&]{r1 = ret4();} );
    thread t2( [&]{r2 = ret6();} );
    // sync
    t1.join();
    t2.join();
    cout << r1 << "+" << r2 << "=" << r1+r2 << endl;

    return 0;
}
```



