//
// Created by Srinath Kailasa on 2019-02-20.
//

#ifndef MPHYG0022CW1_MPHYLINEARMODELSOLVERSTRATEGYI_H
#define MPHYG0022CW1_MPHYLINEARMODELSOLVERSTRATEGYI_H

#include "mphyBasicTypes.h"

class mphyAbstractSolver {
public:
    virtual mphy::LinearSolution GetData(mphy::LabelledData) = 0;
};

#endif //MPHYG0022CW1_MPHYLINEARMODELSOLVERSTRATEGYI_H
