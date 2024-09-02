#include <bits/stdc++.h>
using namespace std;

extern void test_make();
extern void thread_relevant();
extern void pipe_test();
extern void print_odd_and_even_test();
extern void dead_lock_test();

int main() {
    printf("\033[31m------------------------------------------Tests Starting------------------------------------------\033[0m\n");
    test_make();
    thread_relevant();
    pipe_test();
    print_odd_and_even_test();
    dead_lock_test();
    printf("\033[32m------------------------------------------Tests Finished-----------------------------------------\033[0m\n");
    return 0;
}