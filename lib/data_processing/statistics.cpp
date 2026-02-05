// File: lib/data_processing/statistics.cpp
// Description: Implementations for non-template statistics helpers
// INTERNAL LIBRARIES (Use "")
#include "statistics.h"

// This is the source file for the statistics functions.
// The template functions must be declared and defined in the header.

QuaternionRotation quaternionMultiply(QuaternionRotation a, QuaternionRotation b){
    QuaternionRotation temp;
    temp.w = (a.w)*(b.w) - (a.i)*(b.i) - (a.j)*(b.j) - (a.k)*(b.k);
    temp.i = (a.w)*(b.i) + (a.i)*(b.w) + (a.j)*(b.k) - (a.k)*(b.j);
    temp.j = (a.w)*(b.j) - (a.i)*(b.k) + (a.j)*(b.w) + (a.k)*(b.i);
    temp.k = (a.w)*(b.k) + (a.i)*(b.j) - (a.j)*(b.i) + (a.k)*(b.w);
    return temp;
}

QuaternionRotation quaternionInverse(QuaternionRotation q){
    QuaternionRotation temp;
    double normSquared = quaternionNormSquared(q);
    temp = quaternionConjugate(q);
    temp.w /= normSquared;
    temp.i /= normSquared;
    temp.j /= normSquared;
    temp.k /= normSquared;
    return temp;
}

QuaternionRotation quaternionConjugate(QuaternionRotation q){
    QuaternionRotation temp;
    temp.w = q.w;
    temp.i = -q.i;
    temp.j = -q.j;
    temp.k = -q.k;
    return temp;
}

double quaternionNormSquared(QuaternionRotation q){
    return (square <double> (q.w) + square <double> (q.i) + square <double> (q.j) + square <double> (q.k));
}