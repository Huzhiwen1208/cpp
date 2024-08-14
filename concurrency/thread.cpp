#include <bits/stdc++.h>
#include <thread>
using namespace std;

void thread_relevant() {
    printf("\033[35m>>>>>>>>>>> Test thread_relevant Start <<<<<<<<<<<\033[0m\n");

    // 获取当前线程ID
    thread::id main_thread_id = this_thread::get_id();
    cout << "Main thread ID: " << main_thread_id << endl;

    // 当前架构支持的最大并行线程数
    unsigned int thread_nums_of_sys = thread::hardware_concurrency();
    printf("Current supported thread nums: %u\n", thread_nums_of_sys);

    // lambda表达式构建线程
    thread t1([] { cout << "[thread1] hello" << endl; });
    t1.join();

    // 向线程传递参数
    int a = 10;
    thread t2([a] { cout << "[thread2] get arg a: " << a << endl; });
    t2.join();

    // 数据竞争，互斥锁
    int data = 0;
    thread t3([&data] {
        for (int i = 0; i < 10; i++)
            data ++;
    });

    thread t4([&data] {
        for (int i = 0; i < 10; i++) {
            data ++;
        }
    });

    t3.join();
    t4.join();
    cout << "after t3 and t4, data: " << data << endl;

    printf("\033[35m>>>>>>>>>>> Test thread_relevant Passed <<<<<<<<<<<\033[0m\n");
}