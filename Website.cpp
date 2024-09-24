//
// Created by benja on 2021-02-03.
//

#include "Website.h"

Website::Website(const std::string& name, const std::string& address) {

    urlName = name;
    urlAddress = address;
}

Website::Website() {

    urlName = "";
    urlAddress = "";

}
