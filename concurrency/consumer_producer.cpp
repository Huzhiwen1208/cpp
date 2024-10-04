#include <bits/stdc++.h>
using namespace std;

class ProducerConsumerQueue {
public:
    ProducerConsumerQueue(int size) : m_maxSize(size), m_curSize(0) {}

    void push(int & val) {
        std::unique_lock<std::mutex> lock(m_mutex);
        while (m_curSize >= m_maxSize) {
            m_notFull.wait(lock);
        }
        m_queue.push(val);
        ++m_curSize;
        m_notEmpty.notify_one();
    }

    int pop() {
        std::unique_lock<std::mutex> lock(m_mutex);
        while (m_curSize <= 0) {
            m_notEmpty.wait(lock);
        }
        int val = m_queue.front();
        m_queue.pop();
        --m_curSize;
        m_notFull.notify_one();
        return val;
    }

    int size() {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_curSize;
    }

private:
    std::queue<int> m_queue;
    int m_maxSize;
    int m_curSize;
    std::mutex m_mutex;
    std::condition_variable m_notEmpty;
    std::condition_variable m_notFull;
};
void con_prod_test() {
    printf("\033[35m>>>>>>>>>>> Test con_prod Start <<<<<<<<<<<\033[0m\n");
    ProducerConsumerQueue queue(2);

    // 生产者线程
    std::thread producer([&queue] {
        for (int i = 0; i < 10; ++i) {
            cout << "Produced " << i << endl;
            queue.push(i);
        }
    });

    // 消费者线程
    std::thread consumer([&queue] {
        for (int i = 0; i < 10; ++i) {
            int value = queue.pop();
            std::cout << "Consumed " << value << std::endl;
            std::cout << queue.size() << std::endl;
        }
    });

    producer.join();
    consumer.join();
    printf("\033[35m>>>>>>>>>>> Test con_prod Passed <<<<<<<<<<<\033[0m\n");
}