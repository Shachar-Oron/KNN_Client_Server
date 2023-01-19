//
// Created by shach on 15/01/2023.
//

#ifndef AP_EX4_CLI_H
#define AP_EX4_CLI_H

#include <list>
#include <string>
#include "Command.h"

class CLI {
private:
    vector<Command*> commands;
    DefaultIO* dio;


public:
    CLI(DefaultIO* dio);
    void start();
    virtual ~CLI();

};



#endif //AP_EX4_CLI_H
