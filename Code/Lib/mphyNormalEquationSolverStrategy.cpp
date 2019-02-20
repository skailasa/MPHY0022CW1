//
// Created by Srinath Kailasa on 2019-02-20.
//

#include "mphyNormalEquationSolverStrategy.h"

// constructors/destructors
mphyNormalEquationSolverStrategy::mphyNormalEquationSolverStrategy() = default;

mphyNormalEquationSolverStrategy::~mphyNormalEquationSolverStrategy() = default;

// methods
mphy::LinearSolution mphyNormalEquationSolverStrategy::FitData(mphy::LabelledData)
{
    mphy::LinearSolution a;
    a.first = 1;
    a.second = 2;
    return a;
}