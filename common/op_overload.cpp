/**
 * author: Jackhu
 * create_time: 2024-10-05
 * content: operator overload case
 * description: C++中的操作符重载，是多态的一种形式；如函数重载是编译时多态，操作符重载也属于编译时多态。
 *      另外的模板也属于编译时多态。
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct Timer {
    int hour; // 小时
    int minute; // 分钟

    // 重载操作符+号
    Timer operator + (const Timer &other) const {
        Timer result;
        result.hour = this->hour + other.hour + (this->minute + other.minute) / 60;
        result.minute = (this->minute + other.minute) % 60;
        return result;
    }

    // 重载操作符<号
    bool operator < (const Timer &other) const {
        if (this->hour != other.hour)
            return this->hour < other.hour;
        return this->minute < other.minute;
    }
} Timer;

void op_overload_test() {
    printf("\033[35m>>>>>>>>>>> Test op_overload_test Start <<<<<<<<<<<\033[0m\n");

    Timer t1 = {
        .hour = 1,
        .minute = 35,
    };

    Timer t2 = { 2, 30 };
    Timer t3 = t1 + t2; // 测试加号
    vector<Timer> timers = { t1, t2, t3 };
    sort(timers.begin(), timers.end()); // 测试小于号
    for (auto t : timers) {
        printf("%02d:%02d ", t.hour, t.minute);
    }
    cout << endl;

    printf("\033[35m>>>>>>>>>>> Test op_overload_test Passed <<<<<<<<<<<\033[0m\n");
}