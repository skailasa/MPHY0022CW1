
#include <iostream>
#include <random>
#include "mphyLinearDataCreator.h"

namespace mphy {
// constructors/destructors

    LinearDataCreator::LinearDataCreator() = default;

    LinearDataCreator::~LinearDataCreator() = default;

    LinearDataCreator::LinearDataCreator(
            unsigned int seed,
            unsigned int nSamples,
            int low,
            int high) :
            _seed(seed), _nSamples(nSamples), _low(low), _high(high) {};

// methods

    mphy::LabelledData LinearDataCreator::GetData() {

        // Random number generator
        std::default_random_engine generator(this->_seed);
        std::uniform_real_distribution<double> distribution(this->_low,
                                                            this->_high);

        // Buffer to store results
        mphy::LabelledData res(this->_nSamples);

        // Fill buffer with random data
        for (auto i = 0; i < this->_nSamples; i++) {
            double X = distribution(generator);
            double y = distribution(generator);
            res[i].first = X;
            res[i].second = y;
        }

        return res;
    }
}