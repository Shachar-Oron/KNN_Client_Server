//
// Created by liel8 on 23/11/2022.
//
#include <vector>
#include <sstream>
#include <string>

#include "Helpers.h"

using namespace std;

/**
 * Split a string to float vector by a single space
 *
 * @param inputString is the string for splitting.
 *
 * @return a float vector with the string's values.
 */
vector<float> Helpers ::  SplitStringToVector(string inputString) {

    vector<float> vec;
    char delim = ' ';
    stringstream ss (inputString);
    string item;

    while (getline (ss, item, delim)) {
        vec.push_back (stof(item));
    }
    return vec;
}

/**
 * check the validation of the input:
 * - make sure the strings have numbers only.
 * - make sure that both strings have the same length.
 *
 * @param inputString1 the first string.
 * @param inputString2 the second string.

 * @return true if the input is validate, else false.
 */
bool Helpers ::  InputValidation(string inputString1, string inputString2) {
    if (_allIsNumbers(inputString1) && _allIsNumbers(inputString2)
        && (_numOfSpc(inputString1) == _numOfSpc(inputString2)))
        return true;

    return false;
}

/**
 * print float at the appropriate pattern: 1 digit after dot for integer, and 16 digit for Decimal number.
 *
 * @param num the number to print.
 */
void Helpers ::  PrintFloat(float num) {

    if(num - (int)num == 0){
        cout.precision(1);
        cout << fixed << num << endl;
    }
    else {
        cout.precision(16);
        cout << fixed << num << endl;
    }
}

/**
 * a private method for validation that check if all the values in a string are numbers.
 *
 * @param inputString the string for checking.

 * @return true if the string is contains only number, else false.
 */
bool Helpers ::_allIsNumbers(string inputString) {
    while (inputString != "") {
        string substr;
        do {
            string substr = inputString.substr(0, inputString.find(' ') != string::npos ? inputString.find(' ')
                                                                                        : (inputString.length()));
            if (substr[0] == '-' || substr[0] == '+') {
                substr = substr.length() > 1 ? substr.substr(1) : "";
            }
//            makes sure that substring contains at least 1 digit
            if(!isdigit(substr[0])) {
                return false;
            }

            while (isdigit(substr[0])) {
                substr = substr.length() > 1 ? substr.substr(1) : "";
            }

            if (substr[0] == '.') {
                substr = substr.length() > 1 ? substr.substr(1) : "";
            }

            while (isdigit(substr[0])) {
                substr = substr.length() > 1 ? substr.substr(1) : "";
            }

            if (substr != "") {
                return false;
            }
        } while (substr != "");
        inputString = inputString.find(' ') != string::npos ? (inputString.substr(inputString.find(' ')+1)) : "";
    }
    return true;
}

/**
 * a private method for validation that count the spaces in a string.
 *
 * @param inputString the string for counting.

 * @return the number of spaces.
 */
int Helpers ::_numOfSpc(string inputString) {
    int numOfSpace=0;
    for (char  c : inputString) {
        if (c == ' ') {
            numOfSpace++;
        }
    }
    return numOfSpace;
}