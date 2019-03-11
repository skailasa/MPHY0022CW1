/*=============================================================================

  MPHYG0022CW1: CW1, 2019: Linear Regression.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <iostream>
#include <random>
#include "mphyLinearDataCreator.h"

namespace mphy {
    LinearDataCreator::LinearDataCreator() = default;
    LinearDataCreator::~LinearDataCreator() = default;

    LinearDataCreator::LinearDataCreator(
            unsigned int seed,
            unsigned int nSamples,
            int low,
            int high) :
            _seed(seed), _nSamples(nSamples), _low(low), _high(high) {};


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