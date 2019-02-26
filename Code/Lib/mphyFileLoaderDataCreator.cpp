//
// Created by Srinath Kailasa on 2019-02-22.
//

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "mphyFileLoaderDataCreator.h"
#include "mphyExceptionMacro.h"

namespace mphy {
    // constructors/destructors

    FileLoaderDataCreator::FileLoaderDataCreator() = default;

    FileLoaderDataCreator::~FileLoaderDataCreator() = default;

    FileLoaderDataCreator::FileLoaderDataCreator(std::string filepath) :
            _filepath(std::move(filepath)) {};

    // methods

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