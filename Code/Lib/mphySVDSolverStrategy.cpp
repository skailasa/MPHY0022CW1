/*=============================================================================

  MPHYG0022CW1: CW1, 2019: Linear Regression.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

#include "mphySVDSolverStrategy.h"

using namespace Eigen;

namespace mphy {

    SVDSolverStrategy::SVDSolverStrategy() = default;
    SVDSolverStrategy::~SVDSolverStrategy() = default;

    // Strategy to solve the linear least squares problems using SVD
    mphy::LinearSolution SVDSolverStrategy::FitData(mphy::LabelledData data) {
        // Initialise storage buffers
        mphy::LinearSolution result;

        Eigen::MatrixXf X(data.size(), 2);
        Eigen::MatrixXf y(data.size(), 1);

        X = Eigen::MatrixXf::Ones(data.size(), 2);
        y = Eigen::MatrixXf::Zero(data.size(), 1);

        // Copy data to Eigen matrices
        for (int i = 0; i < data.size(); i++) {
            X(i, 1) = data[i].first;
            y(i) = data[i].second;
        }

        JacobiSVD<MatrixXf> svdOfX(X, ComputeThinU | ComputeThinV);
        VectorXf res = svdOfX.solve(y);

        result.first = res(0);
        result.second = res(1);

        return result;
    }
}