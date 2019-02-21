
#include <iostream>
#include <random>
#include "mphyLinearDataCreator.h"

// constructors/destructors

mphyLinearDataCreator::mphyLinearDataCreator() = default;

mphyLinearDataCreator::~mphyLinearDataCreator() = default;

mphyLinearDataCreator::mphyLinearDataCreator(double t0, double t1, double n):
_theta_0(t0), _theta_1(t1), _noise(n){};

// methods

// Helper function to merge together two vectors of doubles
mphy::LabelledData merge(std::vector<double> &A, std::vector<double> &B) {
    mphy::LabelledData target( A.size() < B.size() ? A.size() : B.size());

    for (int i = 0; i < target.size(); i++) {
        target[i] = std::make_pair(A[i], B[i]);
    };
    return target;
}

// Creates 1000 random points (x, y) which can take values between 1 and 100 inc
mphy::LabelledData mphyLinearDataCreator::GetData() {
    std::vector<double> xVec;
    std::vector<double> yVec;

    unsigned int seed = 1;
    unsigned int nSamples = 1000;
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(1,100);

    for (auto i =0; i < nSamples; i++){
        double x = distribution(generator);;
        double Y = distribution(generator);;
        xVec.push_back(x);
        yVec.push_back(Y);
    }

    return merge(xVec, yVec);
}