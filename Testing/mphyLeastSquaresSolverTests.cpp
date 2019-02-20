//
// Created by Srinath Kailasa on 2019-02-20.
//

#include "catch.hpp"
#include "mphyCatchMain.h"
#include "mphyLinearDataCreator.h"

TEST_CASE( "Test instantiation", "[linear-data-creator]" ) {
  mphyLinearDataCreator m(0.1, 0.1, 0.1);
}
