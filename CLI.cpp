//
// Created by shach on 15/01/2023.
//

#include "CLI.h"
#include "Command.h"

using namespace std;

CLI::CLI(DefaultIO* dio) {
    this->dio=dio;
//    UploadCSV upload(dio);
    commands.push_back(new UploadCSV(dio));
    commands.push_back(new Parameters(dio));
    commands.push_back(new RunCSV(dio));
    commands.push_back(new Results(dio));
    commands.push_back(new ResultsFile(dio));
    commands.push_back(new Exit(dio));
    //    list<Command*> commands;
    int k;
    string metric;
}

void CLI::start() {
    int commandIndex = -1;
    InputData inputdata;
    while(commandIndex!=8){
        dio->write("Welcome to the KNN ClassifierServer. Please choose an option:\n");
        for(size_t i=0;i<commands.size();i++){
            string s("1.");
            s[0]=((char)(i+1+'0'));
            dio->write(s);
            dio->write(commands[i]->description+"\n");
        }
        string input = dio->read();
        commandIndex=input[0]-'0'-1;
        if(commandIndex>=0 && commandIndex<=5 || commandIndex == 8)
            commands[commandIndex - 1]->execute(&inputdata);
    }
};




CLI::~CLI() {
    for(size_t i=0;i<commands.size();i++){
        delete commands[i];
    }
}




