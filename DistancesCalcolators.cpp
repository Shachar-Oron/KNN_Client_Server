//
// Created by liel8 on 23/11/2022.
//

#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

#include "DistancesCalcolators.h"

using namespace std;


/**
 * Transfers the data to the relevant calculator.
 *
 * @param CalculatorName is the target calculator short name
 * @param a is the first float vector
 * @param b is the second float vector
 *
 * @return the Euclidean distance, or 0.0 if the vectors are empty.
 */
double DistancesCalcolators::CalculatorsSwitch(const string CalculatorName, const vector<float>& a, const vector<float>& b)
{
    if (CalculatorName == "AUC") {
        return DistancesCalcolators :: EuclideanDistance(a, b);
    }

    else if (CalculatorName == "MAN") {
        return DistancesCalcolators :: ManhattanGeometry(a, b);
    }

    else if (CalculatorName == "CHB") {
        return DistancesCalcolators :: ChebyshevDistance(a, b);
    }

    else if (CalculatorName == "CAN") {
        return DistancesCalcolators :: CanberraDistance(a, b);
    }

    else if (CalculatorName == "MIN") {
        return DistancesCalcolators :: MinkowskiDistance(a, b);
    }
    return 0;
}

/**
 * Calculate the Euclidean distance between 2 vector from the same Dimensions.
 *
 * @param a is the first float vector
 * @param b is the second float vector
 *
 * @return the Euclidean distance, or 0.0 if the vectors are empty.
 */
double DistancesCalcolators::EuclideanDistance(const vector<float>& a, const vector<float>& b)
{
    vector<double>	auxiliary;

    transform (a.begin(), a.end(), b.begin(), back_inserter(auxiliary),//
               [](float element1, float element2) {return pow((element1-element2),2);});
    auxiliary.shrink_to_fit();

    return  sqrt(accumulate(auxiliary.begin(), auxiliary.end(), 0.0));
}

/**
 * Calculate the Manhattan distance between 2 vector from the same Dimensions.
 *
 * @param a is the first float vector
 * @param b is the second float vector
 *
 * @return the Manhattan distance, or 0.0 if the vectors are empty.
 */
double  DistancesCalcolators::ManhattanGeometry(const std::vector<float>& a, const std::vector<float>& b)
{
    std::vector<double>	auxiliary;

    std::transform (a.begin(), a.end(), b.begin(), std::back_inserter(auxiliary),//
                    [](float element1, float element2) {return abs(element1-element2);});
    return  std::accumulate(auxiliary.begin(), auxiliary.end(), 0.0);
}

/**
 * Calculate the Chebyshev distance between 2 vector from the same Dimensions.
 *
 * @param a is the first float vector
 * @param b is the second float vector
 *
 * @return the Chebyshev distance, or 0.0 if the vectors are empty.
 */
double DistancesCalcolators::ChebyshevDistance(const vector<float>& a, const vector<float>& b)
{
    vector<double>	auxiliary;

    transform (a.begin(), a.end(), b.begin(), back_inserter(auxiliary),//
               [](float element1, float element2) {return abs(element1-element2);});
    auxiliary.shrink_to_fit();

    return (*max_element(begin(auxiliary), end(auxiliary)));
}

/**
 * Calculate the Canberra distance between 2 vector from the same Dimensions.
 *
 * @param a is the first float vector
 * @param b is the second float vector
 *
 * @return the Canberra distance, or 0.0 if the vectors are empty.
 */
double DistancesCalcolators::CanberraDistance(const vector<float>& a, const vector<float>& b)
{
    vector<double>	auxiliary;

    transform (a.begin(), a.end(), b.begin(), back_inserter(auxiliary),//
               [](float element1, float element2) {return (abs(element1-element2)/(abs(element1)+abs(element2)));});
    auxiliary.shrink_to_fit();

    return  accumulate(auxiliary.begin(), auxiliary.end(), 0.0);
}

/**
 * Calculate the Minkowski distance between 2 vector from the same Dimensions.
 *
 * @param a is the first float vector
 * @param b is the second float vector
 *
 * @return the Minkowski distance, or 0.0 if the vectors are empty.
 */
double DistancesCalcolators::MinkowskiDistance(const vector<float>& a, const vector<float>& b)
{
    vector<double>	auxiliary;

    transform (a.begin(), a.end(), b.begin(), back_inserter(auxiliary),//
               [](float element1, float element2) {return pow((element1-element2),2);});
    auxiliary.shrink_to_fit();

    return  sqrt(accumulate(auxiliary.begin(), auxiliary.end(), 0.0));
}