/*=============================================================================

  MPHYG0022CW1: CW1, 2019: Linear Regression.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef mphyBasicTypes_h
#define mphyBasicTypes_h

#include "mphyWin32ExportHeader.h"
#include <vector>

/**
* \defgroup internal internal
* \brief Internal stuff, not for end-users.
*/

/**
* \defgroup types types
* \brief Package-wide data types.
*/

/**
* \defgroup utilities utilities
* \brief Groups of c-style functions.
*/

/**
* \defgroup applications applications
* \brief Small, end-user applications, most likely command line.
*/

/**
* \file mphyBasicTypes.h
* \brief Defines types and typedefs used in this library.
* \ingroup types
*/

//! Single namespace for all code in this package
namespace mphy
{
typedef std::vector<std::pair<double, double> > LabelledData;
typedef std::pair<double, double> LinearSolution;
}; // end namespace

#endif
