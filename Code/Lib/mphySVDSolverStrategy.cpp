//
// Created by Srinath Kailasa on 2019-02-22.
//

#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

#include "mphySVDSolverStrategy.h"

using namespace Eigen;

// constructors/destructors

mphySVDSolverStrategy::mphySVDSolverStrategy() = default;

mphySVDSolverStrategy::~mphySVDSolverStrategy() = default;

// methods

mphy::LinearSolution mphySVDSolverStrategy::FitData(mphy::LabelledData data)
{
    // Initialise storage buffers
    mphy::LinearSolution result;

    Eigen::MatrixXf X(data.size(), 2);
    Eigen::MatrixXf y(data.size(), 1);

    X = Eigen::MatrixXf::Ones(data.size(), 2);
    y = Eigen::MatrixXf::Zero(data.size(), 1);

    // Copy data to Eigen matrices
    for (int i=0; i<data.size(); i++) {
        X(i, 1) = data[i].first;
        y(i) = data[i].second;
    }

    JacobiSVD<MatrixXf> svdOfX(X, ComputeThinU | ComputeThinV);
    VectorXf res = svdOfX.solve(y);

    result.first = res(0);
    result.second = res(1);

    return result;
}