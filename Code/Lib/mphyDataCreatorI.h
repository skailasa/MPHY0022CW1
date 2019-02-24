//
// Created by Srinath Kailasa on 2019-02-20.
//

#ifndef MPHYG0022CW1_MPHYDATACREATORI_H
#define MPHYG0022CW1_MPHYDATACREATORI_H

#include "mphyBasicTypes.h"

namespace mphy {

    class AbstractDataCreator {
    public:
        virtual mphy::LabelledData GetData() = 0;
    };

}

#endif //MPHYG0022CW1_MPHYDATACREATORI_H
