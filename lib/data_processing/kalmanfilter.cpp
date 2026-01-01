// File: lib/data_processing/kalmanfilter.cpp
// Description: Kalman filter implementation for scalar measurements
// INTERNAL LIBRARIES (Use "")
#include "kalmanfilter.h"

kFilter::kFilter(double measurementVar, double initialMeasurement){
    var = measurementVar;//Updates initial variance.
    estimate = initialMeasurement;//Updates initial estimate.
};

double kFilter::step(double newMeasurement){
    double kalmanGain = (var/(measVar + var)); //Calculates Kalman gain.
    this->estimate = (kalmanGain * newMeasurement) + (1 - kalmanGain) * (estimate); //Updates estimate
    this->var = (kalmanGain * measVar); //Updates estiamte variance
    return this->estimate; //returns the new estimate
};

double kFilter::rEstimate() const{
    return this->estimate;//returns the estimate
};

double kFilter::rVar() const{
    return this->var;//returns the estimate
}