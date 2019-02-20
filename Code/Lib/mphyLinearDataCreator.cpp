
#include "mphyLinearDataCreator.h"

// constructors/destructors

mphyLinearDataCreator::mphyLinearDataCreator() = default;

mphyLinearDataCreator::~mphyLinearDataCreator() = default;

mphyLinearDataCreator::mphyLinearDataCreator(double t0, double t1, double n):
_theta_0(t0), _theta_1(t1), _noise(n){};

// methods

mphy::LabelledData mphyLinearDataCreator::GetData() {
    mphy::LabelledData m;

    return m;
}