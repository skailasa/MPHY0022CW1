//
// Created by Srinath Kailasa on 2019-02-20.
//

#include "catch.hpp"
#include "mphyCatchMain.h"
#include "mphyLinearDataCreator.h"

TEST_CASE( "Test linear data creator", "[linear-data-creator]")
{
  unsigned int nSamples = 1000;
  unsigned int seed = 1;
  int low = 1;
  int high = 100;

  mphyLinearDataCreator m(seed, nSamples, low, high);
  mphy::LabelledData data = m.GetData();

  // calculate average of generated data
  double yavg;
  double ytotal;
  double xavg;
  double xtotal;

  for(int i=0; i<data.size(); i++) {
    xtotal += data[i].first;
    ytotal += data[i].second;
  }

  yavg = ytotal/nSamples;
  xavg = xtotal/nSamples;

  SECTION("Test correct size") {
    REQUIRE(data.size() == nSamples);
  }

  SECTION("Test approximately correct distribution") {
    REQUIRE(xavg == Approx(50).epsilon(0.05));
    REQUIRE(yavg == Approx(50).epsilon(0.05));
  }
}

