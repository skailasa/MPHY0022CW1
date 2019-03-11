/*=============================================================================

  MPHYG0022CW1: CW1, 2019: Linear Regression.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef MPHYG0022CW1_MPHYNORMALEQUATIONSOLVERSTRATEGY_H
#define MPHYG0022CW1_MPHYNORMALEQUATIONSOLVERSTRATEGY_H

#include "mphyLinearModelSolverStrategyI.h"
namespace mphy {
    // Concrete linear model solver class, that uses the normal equations
    class NormalEquationSolverStrategy : public AbstractSolver {
    public:
        // Default constructors/destructors.
        NormalEquationSolverStrategy();
        ~NormalEquationSolverStrategy();

        mphy::LinearSolution FitData(mphy::LabelledData);
    };
}

#endif //MPHYG0022CW1_MPHYNORMALEQUATIONSOLVERSTRATEGY_H
