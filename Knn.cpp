//
// Created by liel8 on 09/12/2022.
//
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#include "Knn.h"
#include "Helpers.h"
#include "DistancesCalcolators.h"

using namespace std;

int k;
string calculator;

/**
 * knn constructor.
 *
 * @param input_k the number of neighbors.
 * @param input_calculator the alias of the chosen calculator.
 */
Knn::Knn(int input_k, string input_calculator) {
    k = input_k;
    calculator = input_calculator;
}

/**
 * get unclassified vector from the user and match a label according the classified dataset
 *
 * @param classifiedVectors the classified dataset.
 *
 * @return the label of input vector.
 */
string Knn:: RunKnn(vector<StructHeader :: Sample> classifiedVectors) {
    int kNearestDistances[k];
    int i = 0;
    while(i < k) {
        kNearestDistances[i] = INT32_MAX;
        i++;
    }
    StructHeader :: Sample kNearestNeighbor[k];

    string inputVec;
    getline(cin, inputVec);

    vector<float> unclassifiedVec = Helpers :: SplitStringToVector(inputVec);

    for (StructHeader :: Sample classifiedVec : classifiedVectors) {

        int curDistance = DistancesCalcolators :: CalculatorsSwitch(calculator, unclassifiedVec, classifiedVec.vec);
        int i = 1;
        while (i <= k) {
            if (curDistance < kNearestDistances[k-i]) {
                if ((k-i-1 < 0) or (curDistance > kNearestDistances[k-i-1]))
                {
                    kNearestDistances[k-i] = curDistance;
                    kNearestNeighbor[k-i].vec = classifiedVec.vec;
                    kNearestNeighbor[k-i].label = classifiedVec.label;

                    break;
                }

                else {
                    kNearestDistances[k-i] = kNearestDistances[k-i-1];
                    kNearestNeighbor[k-i].vec = kNearestNeighbor[k-i-1].vec;
                    kNearestNeighbor[k-i].label = kNearestNeighbor[k-i-1].label;
                }
            }
            i++;
        }
    }
    map<string, int>labels;
    for (StructHeader :: Sample s: kNearestNeighbor) {
        labels[s.label] = labels[s.label] + 1;
    }

    int maxLabelValue = 0;
    string maxLabelKey;
    map <string,int> :: iterator m;
    for (m = labels.begin(); m!= labels.end(); m++)
    {
        if ((*m).second > maxLabelValue) {
            maxLabelValue = (*m).second;
            maxLabelKey = (*m).first;
        }
    }

    return maxLabelKey;
}
