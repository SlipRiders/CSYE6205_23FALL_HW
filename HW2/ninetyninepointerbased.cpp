/*----------------------------------------------------------------
Copyright (c) 2019 Author: Jagadeesh Vasudevamurthy
file:ninetyninepointerbased.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
compute string- pointer version
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine.h"


/*----------------------------------------------------------------
compute strings pointer based

YOU GET 
n
and you have to generate pointer to string a and pointer to string b

if n = 90
a points to string ninety
b points to empty string
bool is true

if n = 1
a points to string 0ne
b points to empty string
bool is false
----------------------------------------------------------------*/
bool ninetynine::compute_string_(int n, const std::string** a, const std::string** b) {
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
        *a = &below_20[n];
        *b = &tens[0];  // Zero
    } else {
        *a = &tens[n/10];
        if(n%10==0)
            *b = &tens[0];  // Zero
        else
            *b = &below_20[n%10];
    }
    if(n<=1)
        plural=false;
    return plural;
}


/*----------------------------------------------------------------
compute strings using Pointers
*----------------------------------------------------------------*/
void ninetynine::stanzaPointer_(int n) {
  const string* a = nullptr ;
  const string* b = nullptr ;
  const string* c = nullptr ;
  const string* d = nullptr ;
 
  //WRITE CODE 
  //MUST CALL compute_string_
  //MUST CALL PRINT which prints a stanza
  bool plural_a_b = compute_string_(n, &a, &b);
  bool plural_c_d = compute_string_(n-1, &c, &d);
  print_(a, b, plural_a_b, c, d, plural_c_d);
}


//EOF


