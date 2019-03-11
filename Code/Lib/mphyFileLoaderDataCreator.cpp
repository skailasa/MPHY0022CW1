/*=============================================================================

  MPHYG0022CW1: CW1, 2019: Linear Regression.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "mphyFileLoaderDataCreator.h"
#include "mphyExceptionMacro.h"

namespace mphy {

    FileLoaderDataCreator::FileLoaderDataCreator() = default;
    FileLoaderDataCreator::~FileLoaderDataCreator() = default;


    FileLoaderDataCreator::FileLoaderDataCreator(std::string filepath) :
            _filepath(std::move(filepath)) {};

    // Implementation of GetData, throws error if filepath not found
    mphy::LabelledData FileLoaderDataCreator::GetData() {

        mphy::LabelledData res;

        std::ifstream file;

        file.open(this->_filepath);

        if (!file) throw std::runtime_error("Error opening file!");

        std::pair<double, double> input;

        while (file >> input.first >> input.second) {
            res.push_back(input);
        }

        file.close();

        return res;
    }
}