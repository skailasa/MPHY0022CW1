/*=============================================================================

  MPHYG0022CW1: CW1, 2019: Linear Regression.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef mphyWin32ExportHeader_h
#define mphyWin32ExportHeader_h

/**
* \file mphyWin32ExportHeader.h
* \brief Header to sort Windows dllexport/dllimport.
*/

#if (defined(_WIN32) || defined(WIN32)) && !defined(MPHYG0022CW1_STATIC)
  #ifdef MPHYG0022CW1_WINDOWS_EXPORT
    #define MPHYG0022CW1_WINEXPORT __declspec(dllexport)
  #else
    #define MPHYG0022CW1_WINEXPORT __declspec(dllimport)
  #endif  /* MPHYG0022CW1_WINEXPORT */
#else
/* linux/mac needs nothing */
  #define MPHYG0022CW1_WINEXPORT
#endif

#endif
