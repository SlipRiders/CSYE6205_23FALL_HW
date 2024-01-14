/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: ninetynine.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ninetynine class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ninetynine_H
#define ninetynine_H

#include "../util/util.h"

/*----------------------------------------------------------------
Declaration of ninetynine class
-----------------------------------------------------------------*/
class ninetynine{
private:
  const int MAX = 99 ;
  //WRITE ALL PRIVATE FUNCTIONS HERE
  //WRITE ALL STRING INITIALIZATIONS HERE

  static void stanzaReference_(int n);
  static bool compute_string_(int n, std::string &a, std::string &b);
  static void print_(const std::string &a, const std::string &b, bool plural_a_b,const std::string &c, const std::string &d, bool plural_c_d);
  static bool compute_string_(int n, const std::string** a, const std::string** b);
  static void stanzaPointer_(int n);
  static void print_(const std::string *a, const std::string *b, bool plural_a_b,const std::string *c, const std::string *d, bool plural_c_d);

public:
  //NOTHING CAN BE ADDED IN PUBLIC
  void run();
};

#endif

