#include <bits/stdc++.h>
using namespace std;

typedef struct DoubleLinkedList {
    int key;
    int val;
    struct DoubleLinkedList *pre, *next;
    DoubleLinkedList(int key, int val) : key(key), val(val), pre(nullptr), next(nullptr) {}
} DoubleLinkedList;

typedef struct LRU {
    int capacity;
    DoubleLinkedList* head, *tail;
    unordered_map<int, DoubleLinkedList*> mapping;

    void delete_node(DoubleLinkedList* p) {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }

    void append_node(DoubleLinkedList* p) {
        p->pre = this->tail->pre;
        p->next = this->tail;
        this->tail->pre->next = p;
        this->tail->pre = p;
    }

    LRU(int cap) : capacity(cap) {
        head = new DoubleLinkedList(-1, -1);
        tail = new DoubleLinkedList(-1, -1);
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        // 哈希中未找到
        if (this->mapping.find(key) == this->mapping.end())
            return -1;

        // 存在则返回，并且要保持在链表尾
        auto p = mapping[key];
        int result = p->val;
        delete_node(p);
        append_node(p);
        return result;
    }

    void put(int key, int value) {
        // 如果已存在，则修改val即可
        if (this->mapping.find(key) != this->mapping.end())
            mapping[key]->val = value;
        else {
            DoubleLinkedList* s = new DoubleLinkedList(key, value);

            if (this->mapping.size() == this->capacity) {
                // 缓存满了，需要删除一个
                DoubleLinkedList* p = this->head->next;
                this->delete_node(p);
                this->mapping.erase(p->key);
                this->capacity --;
            }

            this->mapping[s->key] = s;
            this->append_node(s);
        }
    }
} LRU;

void lru_test() {
    printf("\033[35m>>>>>>>>>>> Test lru_test Start <<<<<<<<<<<\033[0m\n");

    LRU* component = new LRU(3);

    assert(component->get(15) == -1);
    assert(component->get(10) == -1);
    assert(component->get(20) == -1);

    component->put(3, 15);
    assert(component->get(3) == 15);

    component->put(3, 16);
    assert(component->get(3) == 16);

    component->put(4, 33);
    component->put(5, 44);
    assert(component->get(4) == 33);
    assert(component->get(5) == 44);

    component->put(6, 66);
    assert(component->get(3) == -1);
    assert(component->get(4) == 33);
    assert(component->get(5) == 44);
    assert(component->get(6) == 66);

    printf("\033[35m>>>>>>>>>>> Test lru_test Passed <<<<<<<<<<<\033[0m\n");
}