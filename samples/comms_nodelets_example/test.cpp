/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          http://www.mrpt.org/                          |
   |                                                                        |
   | Copyright (c) 2005-2018, Individual contributors, see AUTHORS file     |
   | See: http://www.mrpt.org/Authors - All rights reserved.                |
   | Released under BSD License. See details in http://www.mrpt.org/License |
   +------------------------------------------------------------------------+ */

#define NODELETS_TEST_VERBOSE
#include "NodeletsTest_impl.cpp"
#include <iostream>

// ------------------------------------------------------
//						MAIN
// ------------------------------------------------------
int main()
{
	try
	{
		NodeletsTest();
		return 0;
	}
	catch (std::exception& e)
	{
		std::cerr << "MRPT exception caught: " << e.what() << std::endl;
		return -1;
	}
	catch (...)
	{
		std::cerr << "Untyped exception!!";
		return -1;
	}
}
