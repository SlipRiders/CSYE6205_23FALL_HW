/*----------------------------------------------------------------
Copyright (c) 2020 Author: Jagadeesh Vasudevamurthy
file: util.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
include this file for all the programs
-----------------------------------------------------------------*/
#pragma once

/*----------------------------------------------------------------
Basic include files
-----------------------------------------------------------------*/
#include <iostream>
#include <fstream>

#include <iomanip>      // std::setprecision
using namespace std;

#ifdef _WIN32
#include <cassert>
#include <ctime>
#else
#include <assert.h>
#include <time.h>
#include <string.h> //for strlen,strcat and strcpy on linux
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

/*--------------------------------------------------------
class random number generator
----------------------------------------------------------*/
class Random {
public:
  Random() { srand((unsigned)time(0)); }
  //Gets a random from including a to including b
  unsigned int get_random_number(unsigned int a = 0, unsigned int b = 10000) const {
    unsigned int upper_bound, lower_bound;
    if (a < b) { upper_bound = b - a; lower_bound = a; } else if (a >= b) { upper_bound = a - b; lower_bound = b; }

    return(lower_bound + rand() % (upper_bound + 1));
  }
  /* no body can copy random or equal random */
  Random(const Random& x) = delete;
  Random& operator=(const Random& x) = delete;
private:

};

/*----------------------------------------------------------------
functions for containers

functors
-----------------------------------------------------------------*/
struct ascendingint {
  bool operator() (const int& a, const int& b) {
    return (a < b) ;
  }
};

struct descendingint {
  bool operator() (const int& a, const int& b) {
    return (a > b) ;
  }
};

struct printint {
  void operator() (const int& a) {
    cout << a << " " ;
  }
};

struct add3int {
  void operator() (int& a) {
    a = a + 3 ;
  }
};

struct displaySignint {
  void operator() (const int& a) {
    if (a > 0) {
      std::cout << "+" ;
    }
    std::cout << a << " " ;
  }
};


//EOF
