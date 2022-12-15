#include <iostream>
#include <string>

#include "DistancesCalcolators.h"
#include "Helpers.h"
#include "Knn.h"
#include "LoadData.h"

using namespace std;
/**
 *
 * make sure that k is an integer
 *
 * @param line is the string
 *
 * @return true if k is a number and false if it doesn't
 */
bool is_valid_k(string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

/**
 *
 * make sure that CalculatorName is valid
 *
 * @param CalculatorName is the string
 *
 * @return true if CalculatorName is a valid and false if it doesn't
 */
bool is_valid_CalculatorName(string CalculatorName) {
    if ((CalculatorName == "CAN") or (CalculatorName == "CHB") or (CalculatorName == "MAN") or (CalculatorName == "AUC") or (CalculatorName == "MIN")) {
        return true;
    }
    else {
        return false;
    }
}


/**
 *
 * this is the main method
 */
int main(int argc, char *argv[])
{
    int k;
    string input;
    string calc_input;
    string calculator;

    if (is_valid_k(argv[1])) {
        k = atoi(argv[1]);

    } else{
        input = argv[1];
        while (is_valid_k(input) == false) {
            cout << "enter a valid k." << endl;
            getline(cin, input);
        }
        k = stoi(input);
    }
    const char* filePath = argv[2];
    int flag = 0;
    calc_input = argv[3];
    while (is_valid_CalculatorName(calc_input) == false) {
        cout << "enter a valid CalculatorName." << endl;
        getline(cin, calc_input);
        flag = 1;
    }
    if (flag == 0) {
        string calculator = argv[3];
    }
    if (flag == 1) {
        string calculator = calc_input;
    }

    Knn obj = Knn(k, calculator);

    LoadData data_set;
    data_set.read_file(filePath);

    for (; true;) {
        cout << obj.RunKnn(data_set.getSampVec()) << endl;
    }
}