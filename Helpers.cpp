//
// Created by liel8 on 23/11/2022.
//
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

#include "Helpers.h"

using namespace std;

/**
 * Split a string to float vector by a single space
 *
 * @param inputString is the string for splitting.
 *
 * @return a float vector with the string's values.
 */
vector<float> Helpers ::  ConvertToFloatVector(vector<string> inputString) {

    vector<float> vec;
    for (string item : inputString) {
//        try {
        vec.push_back (stof(item));
//        }
//        catch (...){
//            throw;
//        }
    }
    return vec;
}

/**
 * Split a string to vector by a single space
 *
 * @param inputString is the string for splitting.
 *
 * @return a vector with the string's values.
 */
vector<string> Helpers ::  SplitStringToStringVector(string inputString) {

    vector<string> vec;
    char delim = ' ';
    stringstream ss (inputString);
    string item;

    while (getline (ss, item, delim)) {
        vec.push_back (item);
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
    else {
//        cout <<"correct length of the vector should be: " << _numOfSpc(inputString1)<< endl;
        return false;
    }
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

bool Helpers :: is_valid_k(string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

bool Helpers :: is_valid_CalculatorName(string CalculatorName) {
    if ((CalculatorName == "CAN")
        or (CalculatorName == "CHB")
        or (CalculatorName == "MAN")
        or (CalculatorName == "AUC")
        or (CalculatorName == "MIN")) {
        return true;
    }
    else {
        return false;
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

/**
 * a method for converting a vector of strings into a single string with spaces in between each element.
 *
 * @param words the vector of strings.

 * @return the string.
 */
string Helpers ::_convertToString(vector<string> words ) {
    string result;

    // Iterate through the vector and concatenate each element to the result, separated by spaces
    for (int i = 0; i < words.size(); i++) {
        result += words[i] + " ";
    }
    return result;
}

/**
 * a method for converting a vector of floats into a single string with spaces in between each element.
 *
 * @param numbers the vector of floats.

 * @return the string.
 */
string Helpers ::_convertToStringFromFloat(vector<float> numbers ) {

    stringstream result;

    // Iterate through the vector and concatenate each element to the result, separated by spaces
    for (int i = 0; i < numbers.size(); i++) {
        result << numbers[i] << " ";
    }

    // Convert the stringstream to a string
    string result_str = result.str();

    return result_str;
}

/**
 * a method that checks if k is bigger than the number of lines in a csv file.
 *
 * @param file_path is the path to the file.
 * @param k is k.
 * @return return true if k is greater than the number of lines, false otherwise.
 */
bool Helpers ::IsKTooLarge(const std::string& file_path, int k) {
    // open the file
    std::ifstream file(file_path);

    // count the number of lines in the file
    int line_count = 0;
    std::string line;
    while (std::getline(file, line)) {
        line_count++;
    }

    // return true if k is greater than the number of lines, false otherwise
    return k > line_count;
}