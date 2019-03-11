#/*============================================================================
#
#  MPHYG0022CW1: CW1, 2019: Linear Regression.
#
#  Copyright (c) University College London (UCL). All rights reserved.
#
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.
#
#  See LICENSE.txt in the top level directory for details.
#
#============================================================================*/

set(DATA_DIR ${CMAKE_SOURCE_DIR}/Testing/Data)
set(TMP_DIR ${CMAKE_BINARY_DIR}/Testing/Temporary)
set(TEST_DATA_1 ${DATA_DIR}/TestData1.txt)
set(TEST_DATA_2 ${DATA_DIR}/TestData2.txt)

set(TEST_CASES mphyLeastSquaresSolverTests)

foreach(_test_case ${TEST_CASES})
  add_executable(${_test_case} ${_test_case}.cpp mphyCatchMain.cpp)
  target_link_libraries(${_test_case} ${MPHYG0022CW1_LIBRARIES} ${ALL_THIRD_PARTY_LIBRARIES})
endforeach()

# Add fixture files to compile definitions
if (TEST_DATA_1)
  target_compile_definitions(mphyLeastSquaresSolverTests PRIVATE TEST_DATA_1="${TEST_DATA_1}")
endif()

if (TEST_DATA_1)
  target_compile_definitions(mphyLeastSquaresSolverTests PRIVATE TEST_DATA_2="${TEST_DATA_2}")
endif()

# Add tests
add_test(project_tests ${EXECUTABLE_OUTPUT_PATH}/mphyLeastSquaresSolverTests)
