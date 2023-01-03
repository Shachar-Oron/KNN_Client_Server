//
// Created by liel8 on 23/11/2022.
//
#include <vector>
#include <sstream>
#include <string>

#include "Helpers.h"

using namespace std;

/**
 * convert a string to float vector
 *
 * @param inputString is the string vector.
 *
 * @return a float vector with the string's values.
 */
vector<float> Helpers ::  ConvertToFloatVector(vector<string> inputString) {

    vector<float> vec;
    for (string item : inputString) {
        if (_isNumbers(item)) {
            vec.push_back (stof(item));
        }
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
    if (_isNumbers(inputString1) && _isNumbers(inputString2)
        && (_numOfSpc(inputString1) == _numOfSpc(inputString2)))
        return true;
    else {
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

/**
 * check if the string is a positive integer.
 *
 * @param line the string for checking.

 * @return true if the string is a positive integer, else false.
 */
bool Helpers :: is_valid_k(string line)
{
    if (_isInteger(line)) {
        return true;
    }
    return false;
}

/**
 * check if the string is one of the calculators name.
 *
 * @param CalculatorName the string for checking.

 * @return true if the string is a calculators name, else false.
 */
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
 * check if the string is at ip pattern.
 *
 * @param input_ip the string for checking.

 * @return true if the string is a ip, else false.
 */
bool Helpers :: is_valid_ip(string input_ip) {
    vector<int> split_ip = _splitIpToIntVector(input_ip);
    for (int num : split_ip) {
        if (num < 0 || num > 255) {
            return false;
        }
    }
        if (split_ip.size() != 4) {
            return false;
        }
    return true;
}

/**
 * check if the string is a valid port integer between 1 - 65536.
 *
 * @param input_port the string for checking.

 * @return true if the string is a valid port, else false.
 */
bool Helpers :: is_valid_port(string input_port) {
    if (_isInteger(input_port)) {
        int port_num = stoi(input_port);
        if (port_num > 0 && port_num < 65536) {
            return true;
        }
    }
    return false;
}

/**
 * check if the vector strings are floats.
 *
 * @param input_vec the vector for checking.

 * @return true if the all the strings are floats, else false.
 */
bool Helpers :: is_float_vec(vector<string> input_vec) {
    for (string item : input_vec){
        if (!_isNumbers(item)) {
            return false;
        }
    }
    return true;
}

/**
 * a private method for validation that check if all the values in a string are numbers.
 *
 * @param inputString the string for checking.

 * @return true if the string is contains only number, else false.
 */
bool Helpers ::_isNumbers(string inputString) {

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
 * a private method for validation that check if the string is a integer.
 *
 * @param inputString the string for checking.

 * @return true if the string is a integer, else false.
 */
bool Helpers ::_isInteger(string inputString) {
    for ( char i : inputString) {
        if (!isdigit(i)) {
            return false;
        }
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

/**
 * a private method for ip validation that split the full string to the numbers
 *
 * @param inputIp the string for counting.

 * @return vector of the string.
 */
vector<int> Helpers ::  _splitIpToIntVector(string inputIp) {

    vector<int> vec;
    char delim = '.';
    stringstream ss (inputIp);
    string item;

    while (getline (ss, item, delim)) {
        if (_isInteger(item)) {
            int int_item = stoi(item);
            vec.push_back(int_item);
        }
        else {
            break;
        }
    }
    return vec;
}