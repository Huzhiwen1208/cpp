#include <bits/stdc++.h>
using namespace std;

extern void lru_test();
extern void op_overload_test();
extern void friend_overload_test();

int main() {
    printf("\033[31m------------------------------------------Tests Starting------------------------------------------\033[0m\n");
    lru_test();
    op_overload_test();
    friend_overload_test();
    printf("\033[32m------------------------------------------Tests Finished-----------------------------------------\033[0m\n");
}