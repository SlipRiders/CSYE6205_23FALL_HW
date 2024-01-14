/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: sarraytest.cpp

On linux:
g++ sarray.cpp sarraytest.cpp
valgrind a.out
-----------------------------------------------------------------*/

#include <crtdbg.h>
#include "sarray.h"

/*----------------------------------------------------------------
                NOTHING CAN BE CHANGED IN THIS FILE
-----------------------------------------------------------------*/
static void testInt() {
		Sarray::show = true;
		{
				Sarray a(20);
				Sarray b(40);
				Sarray c(a);
				b = c;
		}
		assert(Sarray::num_allocated == Sarray::num_freed);
		Sarray::num_allocated = 0;
		Sarray::num_freed = 0;
		{
				Sarray a(20);
				Sarray b(40);
				Swap(a, b);
		}
		cout << "allocated space " << Sarray::num_allocated << endl;
		assert(Sarray::num_allocated == Sarray::num_freed);
		{
				Sarray::num_allocated = 0;
				Sarray::num_freed = 0;
				const int N = 10;
				Sarray a[N];
				for (int i = 0; i < N; ++i) {
						a[i] = Sarray(20);
				}
				cout << "allocated space " << Sarray::num_allocated << endl;
				cout << "freed space " << Sarray::num_freed << endl;
				for (int i = 0; i < N / 2; ++i) {
						int k = N - i - 1;
						cout << "swapping " << i << " to " << k << endl;
						swap(a[i], a[k]);
				}
				cout << "allocated space " << Sarray::num_allocated << endl;
				cout << "freed space " << Sarray::num_freed << endl;
		}
}

static void test_Pass_by_value()
{
    Sarray::show = true;
    {

        Sarray test(1000);
        Sarray::pass_by_value(test);
    }
    cout << "allocated space " << Sarray::num_allocated << endl;
    cout << "freed space " << Sarray::num_freed << endl;
    assert(Sarray::num_allocated == Sarray::num_freed);
    Sarray::num_allocated = 0;
    Sarray::num_freed = 0;
    {
        Sarray test(1000);
        Sarray::pass_by_value(std::move(test));
    }
    cout << "allocated space " << Sarray::num_allocated << endl;
    cout << "freed space " << Sarray::num_freed << endl;
    assert(Sarray::num_allocated == Sarray::num_freed);
    Sarray::num_allocated = 0;
    Sarray::num_freed = 0;
}

static void test_return()
{
    {
        Sarray a = Sarray::return_by_value();
    }
    cout << "allocated space " << Sarray::num_allocated << endl;
    cout << "freed space " << Sarray::num_freed << endl;
    assert(Sarray::num_allocated == Sarray::num_freed);
    Sarray::num_allocated = 0;
    Sarray::num_freed = 0;
}

/*----------------------------------------------------------------

-----------------------------------------------------------------*/
int main()
{ // mainlr
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    testInt();
    cout << "allocated space " << Sarray::num_allocated << endl;
    cout << "freed space " << Sarray::num_freed << endl;
    assert(Sarray::num_allocated == Sarray::num_freed);
    test_Pass_by_value();
    test_return();
    cout << "allocated space " << Sarray::num_allocated << endl;
    cout << "freed space " << Sarray::num_freed << endl;
    assert(Sarray::num_allocated == Sarray::num_freed);
    return 0;
}