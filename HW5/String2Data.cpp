/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: String2Data.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
You cannot include any library here
-----------------------------------------------------------------*/
#include "String2Data.h"

int String2Data::string_2_bool(bool &isBool) {
    if (str_ == "true") {
        isBool = true;
        return 1;
    } else if (str_ == "false") {
        isBool = true;
        return 0;
    }
    isBool = false;
    return 0;
}

long String2Data::string_2_long(bool &isLong) {
    long value;
    stringstream ss(str_);
    ss >> value;
    if (ss.fail() || !ss.eof()) {
        isLong = false;
        return 0;
    }
    isLong = true;
    return value;
}

double String2Data::string_2_double(bool &isDouble) {
    double value;
    stringstream ss(str_);
    ss >> value;
    if (ss.fail() || !ss.eof()) {
        isDouble = false;
        return 0.0;
    }
    isDouble = true;
    return value;
}
/*----------------------------------------------------------------
WRITE CODE
-----------------------------------------------------------------*/
