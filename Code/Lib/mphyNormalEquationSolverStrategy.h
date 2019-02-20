//
// Created by Srinath Kailasa on 2019-02-20.
//

#ifndef MPHYG0022CW1_MPHYNORMALEQUATIONSOLVERSTRATEGY_H
#define MPHYG0022CW1_MPHYNORMALEQUATIONSOLVERSTRATEGY_H

#include "mphyLinearModelSolverStrategyI.h"

class mphyNormalEquationSolverStrategy : public mphyAbstractSolver{
public:
public:
    mphyNormalEquationSolverStrategy();
    ~mphyNormalEquationSolverStrategy();
    mphy::LinearSolution FitData(mphy::LabelledData);
};


#endif //MPHYG0022CW1_MPHYNORMALEQUATIONSOLVERSTRATEGY_H
