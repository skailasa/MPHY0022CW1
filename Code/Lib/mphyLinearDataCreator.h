
#ifndef MPHYG0022CW1_MPHYDATACREATOR_H
#define MPHYG0022CW1_MPHYDATACREATOR_H

#include "mphyDataCreatorI.h"
#include "mphyBasicTypes.h"

class mphyLinearDataCreator: public mphyAbstractDataCreator{
private:
    unsigned int _seed;
    unsigned int _nSamples;
    int _low;
    int _high;
public:
    mphyLinearDataCreator();
    ~mphyLinearDataCreator();
    mphyLinearDataCreator(unsigned int seed, unsigned int nSamples, int low, int high);
    mphy::LabelledData GetData();
};

#endif //MPHYG0022CW1_MPHYDATACREATOR_H
