/*----------------------------------------------------------------
Copyright (c) 2019 Author: Jagadeesh Vasudevamurthy
file: ninetyninereferencebased
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
compute strings. reference based
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine.h"

/*----------------------------------------------------------------
compute strings object based
YOU GET 
n
and you have to generate a and b

if n = 90
a = string Ninety
b = empty string
bool is true

if n = 1
a = string one
b = empty string
bool is false
----------------------------------------------------------------*/
bool ninetynine::compute_string_(int n, std::string &a, std::string &b) {
  bool plural = true;
  //WRITE CODE
    static const std::string below_20[] = {
            "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
            "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
            "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    static const std::string tens[] = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
            "Eighty", "Ninety"
    };
    if (n < 20) {
        a = below_20[n];
        b = "";
    } else {
        a = tens[n/10];
        if(n%10==0)
            b = "";
        else
            b = below_20[n%10];
        }

    if(n<=1) plural=false;
  return plural;
}

/*----------------------------------------------------------------
compute strings using Objects
*----------------------------------------------------------------*/
void ninetynine::stanzaReference_(int n) {

  string a{} ;//null string
  string b{} ;
  string c{} ;
  string d{} ;
 
  //WRITE CODE 
  //MUST CALL compute_string_
  //MUST CALL PRINT which prints a stanza
    bool plural_a_b = compute_string_(n, a, b);
    bool plural_c_d = compute_string_(n-1, c, d);
    print_(a, b, plural_a_b, c, d, plural_c_d);
}


//EOF


