//
// Created by shach on 09/12/2022.
//

#ifndef AP_EX1_2_LOADDATA_H
#define AP_EX1_2_LOADDATA_H
#include <iostream>
#include <vector>

#include "StructHeader.h"
using namespace std;

//struct Sample {
//    vector<float> vec;
//    string label;
//};

class LoadData {

    vector <StructHeader :: Sample> samp_vec;
public:
    void read_file(const char* path);

    const vector<StructHeader :: Sample> &getSampVec() const;

};

bool is_number(const std::string& s);

#endif //AP_EX1_2_LOADDATA_H
