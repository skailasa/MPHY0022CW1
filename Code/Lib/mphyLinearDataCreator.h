/*=============================================================================

  MPHYG0022CW1: CW1, 2019: Linear Regression.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef MPHYG0022CW1_MPHYDATACREATOR_H
#define MPHYG0022CW1_MPHYDATACREATOR_H

#include "mphyDataCreatorI.h"
#include "mphyBasicTypes.h"

namespace mphy {
    // Concrete Data Creator class, that generates random data for fitting,
    // Construct a randomly sampled dataset with the following parameters
    // Seeding allows one to get the same random sample each time, nSamples
    // Is the number of samples generated, and low and high define the bounds
    // Of values in the dataset.
    class LinearDataCreator : public AbstractDataCreator {
    private:
        unsigned int _seed;
        unsigned int _nSamples;
        int _low;
        int _high;
    public:
        // Default constructors/destructors
        LinearDataCreator();
        ~LinearDataCreator();
        // Constructor with parametrisation of randomly sampled dataset
        LinearDataCreator(unsigned int seed, unsigned int nSamples, int low, int high);
        
        mphy::LabelledData GetData();
    };

}

#endif //MPHYG0022CW1_MPHYDATACREATOR_H
