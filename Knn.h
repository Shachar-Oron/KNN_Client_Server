//
// Created by liel8 on 09/12/2022.
//
#include <string>
#include <list>
#include <vector>
#include "StructHeader.h"

using namespace std;

#ifndef AP_EX1_2_KNN_H
#define AP_EX1_2_KNN_H

class Knn {
    int k;
    string calculator;

public:
    Knn();
    Knn(string k, string calculator);

    list<int> kMaxest(list<int> distances);
    string RunKnn(vector<StructHeader :: Sample> classifiedVectors, vector<string> inputVec);
};
#endif //AP_EX1_2_KNN_H
