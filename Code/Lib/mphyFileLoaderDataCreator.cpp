//
// Created by Srinath Kailasa on 2019-02-22.
//

#include <string>
#include <fstream>
#include <iostream>
#include "mphyFileLoaderDataCreator.h"

// constructors/destructors

mphyFileLoaderDataCreator::mphyFileLoaderDataCreator() = default;

mphyFileLoaderDataCreator::~mphyFileLoaderDataCreator() = default;

mphyFileLoaderDataCreator::mphyFileLoaderDataCreator(std::string filepath):
        _filepath(std::move(filepath)){};

// methods

mphy::LabelledData mphyFileLoaderDataCreator::GetData() {

    // Initialise output buffer
    mphy::LabelledData res;

    // Read file and clean up
    std::ifstream infile;
    infile.open(this->_filepath);
    if(infile.fail())
    {
        std::cout << "Error in opening file, check paths" << std::endl;
    }

    else {
        std::pair<double, double> input;

        while (infile >> input.first >> input.second) {
            res.push_back(input);
        }
    }

    infile.close();

    return res;
}