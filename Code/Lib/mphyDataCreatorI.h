/*=============================================================================

  MPHYG0022CW1: CW1, 2019: Linear Regression.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef MPHYG0022CW1_MPHYDATACREATORI_H
#define MPHYG0022CW1_MPHYDATACREATORI_H

#include "mphyBasicTypes.h"

namespace mphy {
    // Class provides abstract interface for loading data files
    class AbstractDataCreator {
    public:
        // Function to load data into a LabelledData type
        virtual mphy::LabelledData GetData() = 0;
    };
}

#endif //MPHYG0022CW1_MPHYDATACREATORI_H
