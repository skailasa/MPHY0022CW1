/*=============================================================================

  MPHYG0022CW1: CW1, 2019: Linear Regression.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <iostream>
#include "Eigen/Dense"
#include "mphyNormalEquationSolverStrategy.h"

namespace mphy {

    NormalEquationSolverStrategy::NormalEquationSolverStrategy() = default;
    NormalEquationSolverStrategy::~NormalEquationSolverStrategy() = default;

    // Strategy to solve the linear least squares problems using the normal equation
    mphy::LinearSolution NormalEquationSolverStrategy::FitData(mphy::LabelledData data) {
        // Initialise storage buffers
        mphy::LinearSolution result;

        Eigen::MatrixXd X(data.size(), 2);
        Eigen::MatrixXd y(data.size(), 1);

        X = Eigen::MatrixXd::Ones(data.size(), 2);
        y = Eigen::MatrixXd::Zero(data.size(), 1);

        // Copy data to Eigen matrices
        for (int i = 0; i < data.size(); i++) {
            X(i, 1) = data[i].first;
            y(i) = data[i].second;
        }

        // Solve normal equation
        Eigen::MatrixXd res = (X.transpose() * X).ldlt().solve(
                X.transpose() * y);

        // Copy result back to solution container
        result.first = res(0);
        result.second = res(1);
        return result;
    }
}