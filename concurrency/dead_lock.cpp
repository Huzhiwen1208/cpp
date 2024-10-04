#include <bits/stdc++.h>
using namespace std;

mutex m1, m2;

void thread1() {
    // P(m1);
    unique_lock<mutex> lock1(m1);
    cout << "thread1 get mutex1\n";
    this_thread::yield();
    // P(m2);
    unique_lock<mutex> lock2(m2);
    cout << "DONE 1" << endl;
}
void thread2() {
    // P(m1);
    unique_lock<mutex> lock1(m2);
    cout << "thread2 get mutex2\n";
    this_thread::yield();
    // P(m2);
    unique_lock<mutex> lock2(m1);
    cout << "DONE 2" << endl;
}

// 两个线程死锁
void dead_lock_test() {
    printf("\033[35m>>>>>>>>>>> Test dead_lock Start <<<<<<<<<<<\033[0m\n");

    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
    
    printf("\033[35m>>>>>>>>>>> Test dead_lock Passed <<<<<<<<<<<\033[0m\n");
}