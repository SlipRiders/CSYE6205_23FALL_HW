/*----------------------------------------------------------------
Copyright (c) 2019 Author: Jagadeesh Vasudevamurthy
file: ninetynine.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ninetynine class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine.h"

/*----------------------------------------------------------------
Ninety nine bottles of beer on the wall,
Ninety nine bottles of beer,
Take one down, pass it around,
Ninety eight bottles of beer on the wall.

One bottle of beer on the wall,
One bottle of beer,
Take one down, pass it around,
Zero bottle of beer on the wall.
(91)
a = Ninety   
b = one   
bool true
(90)
c = Ninety   
d = ""
bool true 

YOU GET a,b, bool
YOU GER c,d, bool

PRINT ONE STANZA HERE
----------------------------------------------------------------*/
void ninetynine::print_(const std::string &a, const std::string &b, bool plural_a_b,const std::string &c, const std::string &d, bool plural_c_d) {
    std::string first_half = a;
    if (!b.empty()) {
        first_half += " " + b;
    }
    first_half += " bottle";
    if (plural_a_b) {
        first_half += "s";
    }
    first_half += " of beer";

    std::string second_half = c;
    if (!d.empty()) {
        second_half += " " + d;
    }
    second_half += " bottle";
    if (plural_c_d) {
        second_half += "s";
    }
    second_half += " of beer on the wall";

    std::cout << first_half << " on the wall," << std::endl;
    std::cout << first_half << "," << std::endl;
    std::cout << "Take one down, pass it around," << std::endl;
    std::cout << second_half << "." << std::endl;
    std::cout << endl;
}

void ninetynine::print_(const std::string *a, const std::string *b, bool plural_a_b,const std::string *c, const std::string *d, bool plural_c_d) {
    std::string first_half = *a;
    if (!b->empty()) {
        first_half += " " + *b;
    }
    first_half += " bottle";
    if (plural_a_b) {
        first_half += "s";
    }
    first_half += " of beer";

    std::string second_half = *c;
    if (!d->empty()) {
        second_half += " " + *d;
    }
    second_half += " bottle";
    if (plural_c_d) {
        second_half += "s";
    }
    second_half += " of beer on the wall";

    std::cout << first_half << " on the wall," << std::endl;
    std::cout << first_half << "," << std::endl;
    std::cout << "Take one down, pass it around," << std::endl;
    std::cout << second_half << "." << std::endl;
    std::cout << endl;
}

/*----------------------------------------------------------------
NOTHING CAN BE CHANGED BELOW
*----------------------------------------------------------------*/
void ninetynine::run() {
  cout << "REFERENCE BASED SONG\n" ;
  for (int i = MAX; i > 0; --i) {
    stanzaReference_(i);
  }
  cout << "POINTER BASED SONG\n" ;
  for (int i = MAX; i > 0; --i) {
    stanzaPointer_(i) ;
  }
}


//EOF
