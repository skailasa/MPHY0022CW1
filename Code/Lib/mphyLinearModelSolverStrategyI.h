/*=============================================================================

  MPHYG0022CW1: CW1, 2019: Linear Regression.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef MPHYG0022CW1_MPHYLINEARMODELSOLVERSTRATEGYI_H
#define MPHYG0022CW1_MPHYLINEARMODELSOLVERSTRATEGYI_H

#include "mphyBasicTypes.h"
namespace mphy {
    // Class provides abstract interface for applying a linear solver method
    class AbstractSolver {
    public:
        // Method that takes linear data and applies a solver method
        virtual mphy::LinearSolution FitData(mphy::LabelledData) = 0;
    };
}

#endif //MPHYG0022CW1_MPHYLINEARMODELSOLVERSTRATEGYI_H
