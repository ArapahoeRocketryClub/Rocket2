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