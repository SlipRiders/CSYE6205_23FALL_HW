/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: util.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
MUST USE ONLT THIS FILE
-----------------------------------------------------------------*/
#pragma once

/*----------------------------------------------------------------
Basic include files
-----------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>      // std::setprecision
using namespace std;

#ifdef _WIN32
#include <cassert>
#include <ctime>
#else
#include <assert.h>
#include <time.h>
#include <string.h> //for strlen,strcat and strcpy on linux
#include <climits>
#include <cfloat>
#endif

//'sprintf' : This function or variable may be unsafe.Consider using sprintf_s instead.To disable deprecation, 
//use _CRT_SECURE_NO_WARNINGS
//To overcome above warning
#ifdef _MSC_VER
#pragma warning(disable: 4996) /* Disable deprecation */
#endif

#include "memory" //For unique_ptr

/*----------------------------------------------------------------
STL
-----------------------------------------------------------------*/
#include <stdexcept> //Without this catch will NOT work on Linux
#include <vector>
#include <string>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric> //iota
#include <iterator> // for iterators
#include <vector> //log
#include <utility> //for pair

//EOF
