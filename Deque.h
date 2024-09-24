//
// Created by benja on 2021-02-03.
//

#ifndef PROJECT1_DEQUE_H
#define PROJECT1_DEQUE_H

#include "Node.h"

class Deque {

private:

    Node *head{};
    Node *tail{};
    int entries{0};

public:

    ~Deque();

    void pushFront(const Website& website);
    void pushBack(const Website& website);
    void popFront();
    void popBack();
    int size() const;
    Node* front();
    Node* back();
    bool empty() const;
    void clear();
    void find(std::string URL);
    void print();
};


#endif //PROJECT1_DEQUE_H
