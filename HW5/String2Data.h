/*----------------------------------------------------------------
All includes here
YOU CANNOT INCLUDE ANY OTHER FILES
-----------------------------------------------------------------*/
#pragma once
#include "util.h"

/*----------------------------------------------------------------
Declaration of String2Data class
-----------------------------------------------------------------*/
class String2Data {
public:
  enum DATATYPE { BOOL = 0, LONG, DOUBLE, STRING };
  void static test_conversion();
  //WRITE CODE
  String2Data(const string& str) : str_(str) {}
  int string_2_bool(bool &isBool);
  long string_2_long(bool &isLong);
  double string_2_double(bool &isDouble);

private:
  //CANNOT ADD ANYTHING
  const string& str_;
};

//EOF

