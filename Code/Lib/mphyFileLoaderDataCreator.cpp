//
// Created by Srinath Kailasa on 2019-02-22.
//

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "mphyFileLoaderDataCreator.h"
#include "mphyExceptionMacro.h"

// constructors/destructors

mphyFileLoaderDataCreator::mphyFileLoaderDataCreator() = default;

mphyFileLoaderDataCreator::~mphyFileLoaderDataCreator() = default;

mphyFileLoaderDataCreator::mphyFileLoaderDataCreator(std::string filepath):
        _filepath(std::move(filepath)){};

// methods

mphy::LabelledData mphyFileLoaderDataCreator::GetData() {

    mphy::LabelledData res;

    try {
        std::ifstream file;

        file.open(this->_filepath);

        if (!file) throw std::runtime_error( "Error opening file!" );

        std::pair<double, double> input;

        while (file >> input.first >> input.second) {
            res.push_back(input);
        }

        file.close();
    }

    catch (std::exception const& e){
        std::cerr << e.what() << '\n';
        throw;
    }
    return res;
}