
#ifndef MPHYG0022CW1_MPHYDATACREATOR_H
#define MPHYG0022CW1_MPHYDATACREATOR_H

#include "mphyDataCreatorI.h"
#include "mphyBasicTypes.h"

class mphyLinearDataCreator: public mphyAbstractDataCreator{
private:
    double _theta_0;
    double _theta_1;
    double _noise;
public:
    mphyLinearDataCreator();
    ~mphyLinearDataCreator();
    mphyLinearDataCreator(double theta_0, double theta_1, double noise);
    mphy::LabelledData GetData();
};

#endif //MPHYG0022CW1_MPHYDATACREATOR_H
