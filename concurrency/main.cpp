#include <bits/stdc++.h>
using namespace std;

extern void test_make();
extern void thread_relevant();
extern void pipe_test();

int main() {
    // 打印红色字体
    printf("\033[31m------------------------------------------Tests Starting------------------------------------------\033[0m\n");
    test_make();
    thread_relevant();
    pipe_test();
    // 打印绿色字体
    printf("\033[32m------------------------------------------Tests Finished-----------------------------------------\033[0m\n");
    return 0;
}