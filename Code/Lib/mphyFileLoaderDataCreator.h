/*=============================================================================

  MPHYG0022CW1: CW1, 2019: Linear Regression.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef MPHYG0022CW1_MPHYFILELOADERDATACREATOR_H
#define MPHYG0022CW1_MPHYFILELOADERDATACREATOR_H

#include <string>
#include "mphyDataCreatorI.h"

namespace mphy {

    // Concrete Data Creator class for loading data from text files
    class FileLoaderDataCreator : public AbstractDataCreator {
    private:
        std::string _filepath;
    public:
        // Default constructors/destructors
        FileLoaderDataCreator();
        ~FileLoaderDataCreator();
        // Constructor which instantiates object with data filepath
        FileLoaderDataCreator(std::string filepath);

        mphy::LabelledData GetData();
    };
}

#endif //MPHYG0022CW1_MPHYFILELOADERDATACREATOR_H
