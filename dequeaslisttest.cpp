//This deque allows you to add and remove nodes in constant time
//In this example we will be storing search history

#include "Deque.h"
#include <iostream>

int main() {

    std::string cmdline;
    Deque deque;

    //loop waits for user input
    while (1) {
        std::getline(std::cin, cmdline);

        //stores first word in command
        int pos_1 = cmdline.find(' ');
        std::string command = cmdline.substr(0, pos_1);

        //adds node to front of queue
        if (command == "push_front") {
            //stores second and third word in command
            int pos_2 = cmdline.find("\" ");
            std::string parameter_1 = cmdline.substr(pos_1+2, pos_2-pos_1-2);
            std::string parameter_2 = cmdline.substr(pos_2+3, cmdline.length()-pos_2-4);

            //creates website object and adds to front of queue
            Website website(parameter_1, parameter_2);
            deque.pushFront(website);
        }

        //adds node to end of queue
        if (command == "push_back") {
            //stores second and third word in command
            int pos_2 = cmdline.find("\" ");
            std::string parameter_1 = cmdline.substr(pos_1+2, pos_2-pos_1-2);
            std::string parameter_2 = cmdline.substr(pos_2+3, cmdline.length()-pos_2-4);

            //creates website object and adds to back of queue
            Website website(parameter_1, parameter_2);
            deque.pushBack(website);
        }

        //deletes node at very front of queue
        if (command == "pop_front") { deque.popFront(); }

        //deletes node at very end of queue
        if (command == "pop_back") { deque.popBack(); }

        //returns size of queue
        if (command == "size") { deque.size(); }

        //returns head node
        if (command == "front") { deque.front(); }

        //returns tail node
        if (command == "back") { deque.back(); }

        //returns bool whether empty or not
        if (command == "empty") { deque.empty(); }

        //deallocates all nodes in queue
        if (command == "clear") { deque.clear(); }

        //finds website based on parameter
        if (command == "find") {
            std::string parameter_1 = cmdline.substr(pos_1+2, cmdline.length()-pos_1-3);
            deque.find(parameter_1);
        }

        //prints all websites in queue
        if (command == "print") { deque.print(); }

        //exits program and frees memory
        if (command == "exit") { break; }
    }

    return 0;
}
