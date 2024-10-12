/**
* author: Jackhu
* time: 2024-10-11 23:53
* content: 智能指针
* description:
*/
#include <bits/stdc++.h>
using namespace std;

class TCA {
public:
    TCA() {
        printf("Built TCA\n");
    }

    virtual ~TCA() {
        printf("Destroy TCA\n");
    }

    void foo() { printf("FOO TCA\n"); }
    void bar() { printf("BAR TCA\n"); }
};

void smart_ptr_test() {
    printf("\033[35m>>>>>>>>>>> Test op_overload_test Start <<<<<<<<<<<\033[0m\n");

    // TCA *a = new TCA();
    unique_ptr<TCA> a = unique_ptr<TCA>(new TCA());
    a->foo();
    a->bar();

    printf("\033[35m>>>>>>>>>>> Test op_overload_test Passed <<<<<<<<<<<\033[0m\n");
}
