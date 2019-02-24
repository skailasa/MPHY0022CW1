//
// Created by Srinath Kailasa on 2019-02-20.
//

#ifndef MPHYG0022CW1_MPHYNORMALEQUATIONSOLVERSTRATEGY_H
#define MPHYG0022CW1_MPHYNORMALEQUATIONSOLVERSTRATEGY_H

#include "mphyLinearModelSolverStrategyI.h"
namespace mphy {
    class NormalEquationSolverStrategy : public AbstractSolver {
    public:
        NormalEquationSolverStrategy();

        ~NormalEquationSolverStrategy();

        mphy::LinearSolution FitData(mphy::LabelledData);
    };
}

#endif //MPHYG0022CW1_MPHYNORMALEQUATIONSOLVERSTRATEGY_H
