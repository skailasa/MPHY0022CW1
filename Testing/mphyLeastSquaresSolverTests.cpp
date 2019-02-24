//
// Created by Srinath Kailasa on 2019-02-20.
//

#include <iostream>
#include "catch.hpp"
#include "mphyCatchMain.h"
#include "mphyLinearDataCreator.h"
#include "mphyNormalEquationSolverStrategy.h"
#include "mphySVDSolverStrategy.h"
#include "mphyFileLoaderDataCreator.h"


TEST_CASE( "Test linear data creator", "[data-creator]")
{
  // Simulation parameters
  unsigned int nSamples = 1000;
  unsigned int seed = 1;
  int low = 1;
  int high = 100;

  mphyLinearDataCreator m(seed, nSamples, low, high);
  mphy::LabelledData data = m.GetData();

  // Calculate average of generated data
  double yAvg;
  double yTotal;
  double xAvg;
  double xTotal;

  for(int i=0; i<data.size(); i++) {
    xTotal += data[i].first;
    yTotal += data[i].second;
  }

  yAvg = yTotal/nSamples;
  xAvg = xTotal/nSamples;

  SECTION("Test correct size") {
    REQUIRE(data.size() == nSamples);
  }

  SECTION("Test approximately correct distribution") {
    REQUIRE(xAvg == Approx(50).epsilon(0.05));
    REQUIRE(yAvg == Approx(50).epsilon(0.05));
  }
}


TEST_CASE("Test file reader", "[file-reader]")
{
  // Read in both test files
  mphy::LabelledData testData1;
  testData1 = mphyFileLoaderDataCreator("Testing/Data/TestData1.txt").GetData();
  // Store first line of file, to check read in value against
  std::pair<double, double> firstLine1(0.170065, 3.38151);

  mphy::LabelledData testData2;
  testData2 = mphyFileLoaderDataCreator("Testing/Data/TestData2.txt").GetData();
  // Store first line of file, to check read in value against
  std::pair<double, double> firstLine2(0.170065, 2.55157);


    SECTION("Test that we can handle incorrect file paths") {
      bool thrown = false;
      try
      {
        mphyFileLoaderDataCreator("FAKE_DATA").GetData();
      }
      catch(const  std::exception& e)
      {
        REQUIRE(std::string(e.what()) == "Error opening file!");
        thrown = true;
      }
      REQUIRE(thrown);
    }

  SECTION("Test file data read correctly") {
    REQUIRE(testData1[0].first == firstLine1.first);
    REQUIRE(testData1[0].second == firstLine1.second);
    REQUIRE(testData2[0].first == firstLine2.first);
    REQUIRE(testData2[0].second == firstLine2.second);
  }

  SECTION("Check correct number of data points read in") {
    REQUIRE(testData1.size() == 1000);
    REQUIRE(testData2.size() == 1000);
  }
}


TEST_CASE("Test normal equation solver", "[model-solver]")
{
  // Simulation parameters
  unsigned int nSamples = 1000;
  unsigned int seed = 1;
  int low = 1;
  int high = 100;

  // Generate random data
  mphyLinearDataCreator m(seed, nSamples, low, high);
  mphy::LabelledData data = m.GetData();

  // Calculate result
  mphy::LinearSolution res = mphyNormalEquationSolverStrategy().FitData(data);

  // These expected values are calculated from the simulation parameters
  SECTION("Test approximately correct y intercept") {
    REQUIRE(res.first == Approx(50).epsilon(0.05));
  }

  SECTION("Test approximately correct gradient") {
    REQUIRE(res.second == Approx(0.0033).epsilon(0.05));
  }

}


TEST_CASE("Test svd solver", "[model-solver]")
{
  // Simulation parameters
  unsigned int nSamples = 1000;
  unsigned int seed = 1;
  int low = 1;
  int high = 100;

  // Generate random data
  mphyLinearDataCreator m(seed, nSamples, low, high);
  mphy::LabelledData data = m.GetData();

  // Calculate result
  mphy::LinearSolution res = mphySVDSolverStrategy().FitData(data);

  // These expected values are calculated from the simulation parameters
  SECTION("Test approximately correct y intercept") {
    REQUIRE(res.first == Approx(50).epsilon(0.05));
  }

  SECTION("Test approximately correct gradient") {
    REQUIRE(res.second == Approx(0.0033).epsilon(0.05));
  }
}
