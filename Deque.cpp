//
// Created by benja on 2021-02-03.
//

#include "Deque.h"
#include <iostream>
#include <algorithm>

Deque::~Deque() {

    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;

}

void Deque::pushFront(const Website& website) {

    Node *node = new Node(website);

    if (head == nullptr) {
        head = node;
        tail = node;
    }
    else {
        node->next = head;
        head->prev = node;
        head = node;
    }

    ++entries;
    std::cout << "success" << std::endl;
}

void Deque::pushBack(const Website& website) {

    Node *node = new Node(website);

    if (tail == nullptr) {
        head = node;
        tail = node;
    }
    else {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }

    ++entries;
    std::cout << "success" << std::endl;
}

void Deque::popFront() {

    if (head == nullptr) {
        std::cout << "failure" << std::endl;
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    }
    else {
        head->prev = nullptr;
    }

    delete temp;
    --entries;

    std::cout << "success" << std::endl;
}

void Deque::popBack() {

    if (tail == nullptr) {
        std::cout << "failure" << std::endl;
        return;
    }

    Node *temp = tail;
    tail = tail->prev;

    if (tail == nullptr) {
        head = nullptr;
    }
    else {
        tail->next = nullptr;
    }

    delete temp;
    --entries;

    std::cout << "success" << std::endl;
}

int Deque::size() const {
    std::cout << "size is " << entries << std::endl;
    return entries;
}

Node* Deque::front() {

    if (head == nullptr) {
        std::cout << "failure" << std::endl;
        return nullptr;
    }

    std::cout << "front is " << head->website.urlName << " " << head->website.urlAddress << std::endl;
    return head;
}

Node* Deque::back() {

    if (tail == nullptr) {
        std::cout << "failure" << std::endl;
        return nullptr;
    }

    std::cout << "back is " << tail->website.urlName << " " << tail->website.urlAddress << std::endl;
    return tail;
}

bool Deque::empty() const {

    if (entries == 0) {
        std::cout << "empty 1" << std::endl;
        return true;
    }

    std::cout << "empty 0" << std::endl;
    return false;
}

void Deque::clear() {

    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
    entries = 0;

    std::cout << "success" << std::endl;
}

void Deque::find(std::string URL) {

    Node *temp = head;
    std::string lowerURL = URL;
    std::transform(lowerURL.begin(), lowerURL.end(), lowerURL.begin(),[](unsigned char c){ return tolower(c); });

    while (temp != nullptr) {

        std::string urlName = temp->website.urlName;
        std::transform(urlName.begin(), urlName.end(), urlName.begin(),[](unsigned char c){ return tolower(c); });

        if (urlName == lowerURL) {
            std::cout << "found " << temp->website.urlName << " " << temp->website.urlAddress << std::endl;
            return;
        }
        temp = temp->next;
    }

    std::cout << "not found " << URL << std::endl;
}

void Deque::print() {

    Node *temp = tail;

    while (temp != nullptr) {

        std::cout << temp->website.urlName << " " << temp->website.urlAddress << std::endl;
        temp = temp->prev;
    }
}


