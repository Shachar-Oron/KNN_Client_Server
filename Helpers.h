//
// Created by liel8 on 23/11/2022.
//
#include <iostream>
#include <vector>

using namespace std;

#ifndef AP_EX1_2_HELPERS_H
#define AP_EX1_2_HELPERS_H


class Helpers {
public:
    static vector<float> SplitStringToVector(string inputString1);
    bool InputValidation(string inputString1, string inputString2);
    void PrintFloat(float num);

private:
    bool _allIsNumbers(string inputString);
    int _numOfSpc(string inputString);
};


#endif //AP_EX1_2_HELPERS_H
