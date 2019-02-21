
#include <iostream>
#include <random>
#include "mphyLinearDataCreator.h"

// constructors/destructors

mphyLinearDataCreator::mphyLinearDataCreator() = default;

mphyLinearDataCreator::~mphyLinearDataCreator() = default;

mphyLinearDataCreator::mphyLinearDataCreator(double t0, double t1, double n):
_theta_0(t0), _theta_1(t1), _noise(n){};

// methods

// Creates 1000 random points (x, y) which can take values between 1 and 100 inc
mphy::LabelledData mphyLinearDataCreator::GetData() {

    // Parameters to seed random data points
    unsigned int seed = 1;
    unsigned int nSamples = 1000;
    unsigned int low = 1;
    unsigned int high = 100;

    // Random number generator
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(low, high);

    // Buffer to store results
    mphy::LabelledData res(nSamples);

    // Fill buffer with random data
    for (auto i=0; i < nSamples; i++){
        double X = distribution(generator);
        double y = distribution(generator);
        res[i].first = X;
        res[i].second = y;
    }

    return res;
}