//
// Created by Srinath Kailasa on 2019-02-22.
//

#ifndef MPHYG0022CW1_MPHYSVDSOLVERSTRATEGY_H
#define MPHYG0022CW1_MPHYSVDSOLVERSTRATEGY_H

#include "mphyLinearModelSolverStrategyI.h"

class mphySVDSolverStrategy: public mphyAbstractSolver{
public:
    mphySVDSolverStrategy();
    ~mphySVDSolverStrategy();
    mphy::LinearSolution FitData(mphy::LabelledData);
};


#endif //MPHYG0022CW1_MPHYSVDSOLVERSTRATEGY_H
