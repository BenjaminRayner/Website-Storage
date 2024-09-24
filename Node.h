//
// Created by benja on 2021-02-03.
//

#ifndef PROJECT1_NODE_H
#define PROJECT1_NODE_H

#include "Website.h"

class Node {

public:
    explicit Node(const Website& data);

    Website website;
    Node *next{};
    Node *prev{};
};


#endif //PROJECT1_NODE_H
