
#ifndef MPHYG0022CW1_MPHYDATACREATOR_H
#define MPHYG0022CW1_MPHYDATACREATOR_H

#include "mphyDataCreatorI.h"
#include "mphyBasicTypes.h"

namespace mphy {

    class LinearDataCreator : public AbstractDataCreator {
    private:
        unsigned int _seed;
        unsigned int _nSamples;
        int _low;
        int _high;
    public:
        LinearDataCreator();

        ~LinearDataCreator();

        LinearDataCreator(unsigned int seed, unsigned int nSamples, int low, int high);

        mphy::LabelledData GetData();
    };

}

#endif //MPHYG0022CW1_MPHYDATACREATOR_H
