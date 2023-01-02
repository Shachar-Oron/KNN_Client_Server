//
// Created by shach on 09/12/2022.
//

using namespace std;
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "LoadData.h"


/**
 * function that determine weather a string is a double
 *
 * @param s is the string we are checking.
 *
 * @return true if the string is a double, else false
 */
bool is_number(const std::string& s)
{
    try {
        double d = stod(s);
        return true;
    } catch (...) {
        return false;
    }
}

/**
 *
 * upload data from csv file and put it un a vector
 *
 * @param path is the path to the file.
 *
 * @return none
 */
void LoadData::read_file(const char* path) {
    cout<< "path: " << path << endl;

    ifstream my_file (path);
    string my_line;
    // check whether the file is open
    if (my_file.is_open()) {
        while(getline(my_file, my_line)) {

            // used for breaking words
            stringstream s(my_line);
            StructHeader :: Sample my_sample;
            string word;

            // read every column data of a row and
            // store it in a string variable, 'word'
            while ( getline(s, word, ',')) {
                if(is_number(word)) {
                    my_sample.vec.push_back(stof(word));
                }
                else {
                    my_sample.label = word;
                }
            }
            samp_vec.push_back(my_sample);
        }
        my_file.close();
    }
    else {
        cout<< "could not open file. "<< endl;
    }
}

/**
 *
 * the getter of the LoadData class.
 *
 * @return the samp_vec
 */
const vector<StructHeader :: Sample> &LoadData::getSampVec() const {
    return samp_vec;
}
