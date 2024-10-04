/**
* author: Jackhu
* time: 2024-10-05 01:24
* content: friend operator overload
* description: 友元函数，可以使类的非成员函数重载类的操作符，比成员函数重载更加优秀
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

    // 友元函数重载*号
    friend Timer operator * (const int &count, Timer &timer);
    // 友元函数重载<<
    friend ostream &operator << (ostream &os, Timer &timer);
} Timer;

Timer operator * (const int &count, Timer &timer) {
    return { timer.hour * count + timer.minute * count / 60, timer.minute * count % 60 };
}

ostream &operator << (ostream &os, Timer &timer) {
    os << "Timer { hour=" << timer.hour << ", minute=" << timer.minute << " }";
    return os;
}

void friend_overload_test() {
    printf("\033[35m>>>>>>>>>>> Test op_overload_test Start <<<<<<<<<<<\033[0m\n");

    Timer t = {
        .hour = 3,
        .minute = 40,
    };

    Timer tm = 3 * t;
    cout << "The result of 3 * " << t << " = " << tm << endl;

    printf("\033[35m>>>>>>>>>>> Test op_overload_test Passed <<<<<<<<<<<\033[0m\n");
}
