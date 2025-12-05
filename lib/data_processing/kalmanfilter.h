#pragma once  // Makes sure this file is included only once during compilation to avoid duplicates
//Class which allows for the filtering of raw input data.

class kFilter{
    private:
        double measVar; // Measurement variance should be known to use the filter effectively.
    
        double var; // Variance of current estimate. 
        double estimate; // current estimate.
    public:
        kFilter(double measurementVar, double initialMeasurement);//constructor
        double step(double newMeasurement);//updates estimate using new measurment
        double rEstimate() const;//Reads the estimate
        double rVar() const;//Reads the variance
};