//
// Created by liel8 on 23/11/2022.
//
#include <vector>

using namespace std;

#ifndef AP_EX1_2_DISTANCESCALCOLATORS_H
#define AP_EX1_2_DISTANCESCALCOLATORS_H

class DistancesCalcolators {

public:
    static double CalculatorsSwitch(const string CalcolatorName, const vector<float>& a, const vector<float>& b);
    static double EuclideanDistance(const vector<float>& a, const vector<float>& b);
    static double ManhattanGeometry(const vector<float>& a, const vector<float>& b);
    static double ChebyshevDistance(const vector<float>& a, const vector<float>& b);
    static double CanberraDistance(const vector<float>& a, const vector<float>& b);
    static double MinkowskiDistance(const vector<float>& a, const vector<float>& b);
};


#endif //AP_EX1_2_DISTANCESCALCOLATORS_H