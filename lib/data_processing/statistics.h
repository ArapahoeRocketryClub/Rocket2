#include "header.h"
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

QuaternionRotation quaternionMultiply(QuaternionRotation, QuaternionRotation);//<ultiplies two quternions using Hamiltonian product. This is useful for handling rotation data.