/*----------------------------------------------------------------
Copyright (c) 2022 Author: Jagadeesh Vasudevamurthy
file: p2test.cpp

On linux:
g++ p2.cpp p2test.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
													YOU CANNOT CHANGE ANYTHING IN THIS FILE
													DO NOT UPLOAD THIS FILE ON CANVAS
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test p1 object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "p2.h"

/*----------------------------------------------------------------
print n empty lines
-----------------------------------------------------------------*/
static void emptylines(int n) {
		for (int i = 0; i < n; ++i) {
				cout << endl;
		}
}

/*----------------------------------------------------------------
test1
-----------------------------------------------------------------*/
static void test1() {
		const int n = 1;
		const char c = '*';
		p2 a;
		{
				for (int i = 1; i < 10; ++i) {
						int num = a.d1(i, c);
						int e = (i * (i + 1)) / 2;
						if (num != e) {
								cout << "expected " << c << " for n = " << i << " is " << e << " but your answer = " << num << endl;
								assert(0);
						}
						emptylines(n);
				}
				int i = 21;
				int num = a.d1(21, c);
				int e = (i * (i + 1)) / 2;
				if (num != e) {
						cout << "expected " << c << " for n = " << i << " is " << e << " but your answer = " << num << endl;
						assert(0);
				}
				emptylines(n);
		}
		{
				for (int i = 1; i < 10; ++i) {
						int num = a.d2(i, c);
						int e = (i * (i + 1)) / 2;
						if (num != e) {
								cout << "expected " << c << " for n = " << i << " is " << e << " but your answer = " << num << endl;
								assert(0);
						}
						emptylines(n);
				}
				int i = 21;
				int num = a.d2(21, c);
				int e = (i * (i + 1)) / 2;
				if (num != e) {
						cout << "expected " << c << " for n = " << i << " is " << e << " but your answer = " << num << endl;
						assert(0);
				}
				emptylines(n);
		}
		{
				for (int i = 1; i < 10; i = i + 2) {
						int num = a.d3(i, c); //i is guaranteed to be odd
						int e = 1;
						if (i > 1) {
								int k = i - 2; //k rows has 2 stars
								//First and last row has 1 star
								e = 2 * k + 2;
						}
						if (num != e) {
								cout << "expected " << c << " for n = " << i << " is " << e << " but your answer = " << num << endl;
								assert(0);
						}
						emptylines(n);
				}
				int i = 21;
				int num = a.d3(i, c); //i is guaranteed to be odd
				int k = i - 2; //k rows has 2 stars
				//First and last row has 1 star
				int e = 2 * k + 2;
				if (num != e) {
						cout << "expected " << c << " for n = " << i << " is " << e << " but your answer = " << num << endl;
						assert(0);
				}
				emptylines(n);
		}
		{
				for (int i = 1; i < 10; ++i) {
						int num = a.d4(i, c);
						int e = 1;
						if (i > 1) {
								int k = i - 1;
								e = 2 * ((k *(k+1))/2) + i;
						}
						if (num != e) {
								cout << "expected " << c << " for n = " << i << " is " << e << " but your answer = " << num << endl;
								assert(0);
						}
						emptylines(n);
				}
				int i = 21;
				int num = a.d4(21, c);
				int k = i - 1;
				int e = 2 * ((k * (k + 1)) / 2) + i;
				if (num != e) {
						cout << "expected " << c << " for n = " << i << " is " << e << " but your answer = " << num << endl;
						assert(0);
				}
				emptylines(n);
		}
		{
				for (int i = 1; i < 10; ++i) {
						int num = a.d5(i, c);
						int e = 1;
						if (i > 1) {
								int k = i - 1;
								e = 2 * ((k * (k + 1)) / 2) + i;
						}
						if (num != e) {
								cout << "expected " << c << " for n = " << i << " is " << e << " but your answer = " << num << endl;
								assert(0);
						}
						emptylines(n);
				}
				int i = 21;
				int num = a.d5(21, c);
				int k = i - 1;
				int e = 2 * ((k * (k + 1)) / 2) + i;
				if (num != e) {
						cout << "expected " << c << " for n = " << i << " is " << e << " but your answer = " << num << endl;
						assert(0);
				}
				emptylines(n);
		}
		{
				for (int i = 1; i < 10; ++i) {
						int num = a.d6(i, c);
						int e = 2 * ((i * (i + 1)) / 2);
						if (num != e) {
								cout << "expected " << c << " for n = " << i << " is " << e << " but your answer = " << num << endl;
								assert(0);
						}
						emptylines(n);
				}
				int i = 21;
				int num = a.d6(21, c);
				int k = i;
				int e = 2 * ((i * (i + 1)) / 2);
				if (num != e) {
						cout << "expected " << c << " for n = " << i << " is " << e << " but your answer = " << num << endl;
						assert(0);
				}
				emptylines(n);
		}
		{
				//a.riceOnChessBoard(64);
				//emptylines(n);
		}
}

/*----------------------------------------------------------------
testbed
-----------------------------------------------------------------*/
static void testbed() {
		test1();
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {

		testbed();
		return 0;
}

//EOF
