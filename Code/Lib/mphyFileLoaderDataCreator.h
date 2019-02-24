//
// Created by Srinath Kailasa on 2019-02-22.
//

#ifndef MPHYG0022CW1_MPHYFILELOADERDATACREATOR_H
#define MPHYG0022CW1_MPHYFILELOADERDATACREATOR_H

#include <string>
#include "mphyDataCreatorI.h"

namespace mphy {

    class FileLoaderDataCreator : public AbstractDataCreator {
    private:
        std::string _filepath;
    public:
        FileLoaderDataCreator();

        ~FileLoaderDataCreator();

        FileLoaderDataCreator(std::string filepath);

        mphy::LabelledData GetData();
    };

}

#endif //MPHYG0022CW1_MPHYFILELOADERDATACREATOR_H
