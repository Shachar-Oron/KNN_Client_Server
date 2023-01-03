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
    static vector<float> ConvertToFloatVector(vector<string> inputString1);
    static vector<string> SplitStringToStringVector(string inputString1);
    bool InputValidation(string inputString1, string inputString2);
    void PrintFloat(float num);
    static bool is_valid_CalculatorName(string CalculatorName);
    static bool is_valid_k(string line);
    string _convertToString(vector<string> words );
    string _convertToStringFromFloat(vector<float> numbers );
    bool IsKTooLarge(const std::string& file_path, int k);

private:
    bool _allIsNumbers(string inputString);
    int _numOfSpc(string inputString);
};


#endif //AP_EX1_2_HELPERS_H
