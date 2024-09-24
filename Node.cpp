//
// Created by benja on 2021-02-03.
//

#include "Node.h"

Node::Node(const Website& data) {

    website = data;
    next = nullptr;
    prev = nullptr;
}
