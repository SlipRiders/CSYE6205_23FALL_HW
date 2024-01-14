/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: magicsquare.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has magicsquare class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef magicsquare_H
#define magicsquare_H

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

#include <stdexcept> //Without this catch will NOT work on Linux
#include <vector>
#include <string>

/*----------------------------------------------------------------
Declaration of magicsquare class

vector<vector<int>*>* matrix_;

vector<int> a ; // a is a vector of int of unlimited size

vector<int>* b ; //b is a pointer to a

vector<vector<int>*>[n_] c ; c is a vector of size n_ that has b. That means c is a vector of pointers to a

matrix is  a pointer to c
-----------------------------------------------------------------*/
class magicsquare{
public:
  static bool show;
  //WRITE ALL PUBLIC FUNCTION BELOW
  //operator
  explicit magicsquare(int n);

    //copy constructor
    magicsquare(const magicsquare& other);

    //copy assignment operator
    magicsquare& operator=(const magicsquare& other);

    //Destructor
    ~magicsquare();

    int getRC(int r, int c) const;

    //output assignment operator
    friend std::ostream& operator<<(std::ostream& out, const magicsquare& ms);


private:
  //Only data structure allowed. Cannot change
  //You cannot add any other data members
  const int n_;
  vector<vector<int>*>* matrix_; //YOU CANNOT CHANGE THIS
  //ALL Private functions below
};

#endif
