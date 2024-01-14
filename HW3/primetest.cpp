/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: primetest.cpp

On linux:
g++ prime.cpp primetest.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test prime
NOTHING CAN BE CHANGED IN THIS FILE. DO NOT upload to canvas
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include <crtdbg.h>
#include "prime.h"

/*----------------------------------------------------------------
print
-----------------------------------------------------------------*/
static void print(const string& name, unsigned long long  work, double time_elapsed_ms, const vector<int>& v, bool full = false) {
		if (full) {
				const int MAX = 13;
				int k = 0;
				for (const int& e : v) {
						cout << e << " ";
						++k;
						if (k % MAX == 0) {
								k = 0;
								cout << endl;
						}
				}
				cout << endl;
		}
  cout << name << " Has " << v.size() << " Primes. " << "Work  = " << work << " CPU time used: " << time_elapsed_ms / 1000 << " seconds\n";
}


/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
static void testbed() {
		{
				//const string algname[] = { "upto_n_minus_1", "upto_n_by_2", "sqrt_of_n", "upto_prime","sieve_of_eratosthenes" };
				const string algname[] = { "upto_n_minus_1", "upto_n_by_2", "sqrt_of_n" };
				const int na[] = { 25, 100,1000,10000,100000,1000000,10000000,100000000 };
				const int num_prime[] = { 9, 25,168,1229,9592,78498,664579,5761455 };
				const int max = 1000000;
				
				int i = -1;
				for (int n : na) {
						cout << "----------- n = " << n << " -----------------\n";
						++i;
						vector<vector<int>> ans;
						bool cannot_compute = false;
						for (const string& name : algname) {
								if ((n >= max) && ((name == "upto_n_minus_1") || (name == "upto_n_by_2") || (name == "sqrt_of_n")) ){
										cout << "cannot compute prime by " << name << " algorithm\n";
										cannot_compute = true;
										continue;
								}
								vector<int> a;
								prime::reset_kount();
								std::clock_t c_start = std::clock();
								prime o(a, name, n);
								std::clock_t c_end = std::clock();
								double time_elapsed_ms = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
								unsigned long long work = o.get_kount();
								print(name, work, time_elapsed_ms, a);
								auto s = a.size();
								assert(s == num_prime[i]);
								ans.push_back(a);
						}
						if (cannot_compute) {
								//"upto_prime","sieve_of_eratosthenes"
								if (ans.size()) {
										assert(ans[0] == ans[1]); //ans[0] has upto_prime and ans[1] has sieve_of_eratosthenes
								}
						}else {
								for (auto i = 1; i < sizeof(algname)/sizeof(string); ++i) {
										assert(ans[0] == ans[i]);
								}
						}
				}
		}
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() { //mainprime
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  testbed();
  cout << "All test passed\n" ;
  return 0;
}

//EOF


