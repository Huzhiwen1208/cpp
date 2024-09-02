#include <bits/stdc++.h>
using namespace std;

int num = 1;
mutex m;
condition_variable cv;
bool isOddTurn = true;

void print_odd() {
    while (num <= 100) {
        // P mutex
        unique_lock<mutex> lock(m);
        cv.wait(lock, [] {return isOddTurn;} );
        if (num <= 100) {
            cout << "Thread 1: " << num << endl;
            num++;
        }
        isOddTurn = false;
        // V mutex
        cv.notify_all();
    }
}

void print_even() {
    while (num <= 100) {
        // P mutex
        unique_lock<mutex> lock(m);
        cv.wait(lock, [] {return !isOddTurn;});
        if (num <= 100) {
            cout << "Thread 2: " << num << endl;
            num++;
        }
        isOddTurn = true;
        // V mutex
        cv.notify_all();
    }
}

// 两个线程交替打印1-100
int print_odd_and_even_test() {
    printf("\033[35m>>>>>>>>>>> Test print Start <<<<<<<<<<<\033[0m\n");

    thread t1(print_odd);
    thread t2(print_even);
    t1.join();
    t2.join();

    printf("\033[35m>>>>>>>>>>> Test print Start <<<<<<<<<<<\033[0m\n");
}