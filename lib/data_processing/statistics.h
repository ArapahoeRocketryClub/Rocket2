// File: lib/data_processing/statistics.h
// Description: Statistical helpers and quaternion utilities used by data processing

#ifndef STATISTICSLIB
#define STATISTICSLIB

// INTERNAL LIBRARIES (Use "")
#include "global.h"

// Collection of statistics functions which might be useful, especially for data

//returns the square of the argument
template <typename type> type square(type val){
    return (val * val);
};

//takes a pointer to an array and sums the values. 
template <typename type> type sum(type* currentVal, int numTerms){
    type partialSum = *currentVal; //initializes partial sum
    for(int i = 0; i < numTerms - 1; i++){
        currentVal += 1;//increments the pointer
        partialSum += *currentVal;//updates partial sum
    }

    return partialSum;
};

//sum but multiplies the result by a scalar
template <typename type> type weightedSum(type* firstElement, int numTerms, type weight){
    return (weight * sum<type>(firstElement, numTerms));
};

//sum but divides by the number of elements
template <typename type> type mean(type* firstElement, int numTerms){
    return sum<type>(firstElement, numTerms) / static_cast<type>(numTerms);
};

//finds the sample variance of an array using a pointer to the first element and the number of terms
template <typename type> type sampVar(type* currentVal, int numTerms){
    type avg = mean(currentVal, numTerms);
    type partialSquareSum = square(*currentVal - avg);
    for(int i = 0; i < numTerms - 1; i++){
        currentVal += 1;
        partialSquareSum += square(*currentVal - avg);
    }
    return partialSquareSum / static_cast<type>(numTerms - 1);
};

QuaternionRotation quaternionMultiply(QuaternionRotation, QuaternionRotation);//multiplies two quternions using Hamiltonian product. This is useful for handling rotation data.
QuaternionRotation quaternionInverse(QuaternionRotation);//Returns the inverse of a quaternion.
double quaternionNormSquared(QuaternionRotation);//Returns the norm squared of a quaternion. (q1^2 + q2^2 + q3^2 + q4^2)
QuaternionRotation quaternionConjugate(QuaternionRotation);//Returns the conjugate of a quaternion. q* = (q0, -q1, -q2, -q3)
QuaternionRotation swingTwistDecompositionPartial(Position axis,QuaternionRotation rotation);//Returns twist part of quaternion rotation
QuaternionRotation normQuaternion(QuaternionRotation rotation);
#endif