//
// Created by benja on 2021-02-03.
//

#ifndef PROJECT1_WEBSITE_H
#define PROJECT1_WEBSITE_H

#include <string>

class Website {

public:
    Website(const std::string& name, const std::string& address);
    Website();

    std::string urlName;
    std::string urlAddress;
};


#endif //PROJECT1_WEBSITE_H
