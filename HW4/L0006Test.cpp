/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: L0006test.cpp

on linus:
g++ L0006test.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
6. Zigzag Conversion
https://leetcode.com/problems/zigzag-conversion/
---------------------------------------------------------------- - */

/*----------------------------------------------------------------
YOU CANNOT CHANGE THIS FILE.
DO NOT UPLOAD IN CANVAS
---------------------------------------------------------------- - */

/*----------------------------------------------------------------
all includes here
-----------------------------------------------------------------*/
//You must include L0006.cpp, as class L0006 is in cpp file. 
//DO NOT INCLUDE L0006.cpp in project
//basically it is just one big cpp file

#include <crtdbg.h>
#include "util.h"
#include "L0006.cpp" 

/*----------------------------------------------------------------
NOTHING CAN BE CHANGED IN THIS FILE
---------------------------------------------------------------- - */
class L0006test{
public:
		L0006test(){ test_();}
private:
		void test_();
		
};


void L0006test::test_() {
		bool show = true;
		{
				const string s = "PAYPALISHIRING";
				string ans;
				int r = 3;
				L0006 a(s, r, ans, show);
				assert(ans == "PAHNAPLSIIGYIR");
		}
		{
				const string s = "PAYPALISHIRING";
				string ans;
				int r = 4;
				L0006 a(s, r, ans, show);
				assert(ans == "PINALSIGYAHRPI");
		}
		{
				const string s = "A";
				string ans;
				int r = 1;
				L0006 a(s, r, ans, show);
				assert(ans == "A");
		}
		{
				const string s = "Jagadeesh Vasudevamurthy";
				string ans;
				int r = 4;
				L0006 a(s, r, ans, show);
				assert(ans == "JesmaesauauygdhVdvrha et");
		}
		{
				const string s = "Long years ago, we made a tryst with destiny. Now the time has come when we shall redeem our pledge - not wholly or in full measure - but very substantially. At the stroke of the midnight hour, when the world sleeps, India will awake to life and freedom. A moment comes, but rarely in history, when we step out from the old to the new, when an age ends, and when the soul of a nation, long suppressed, finds utterance";
				string ans;
				int r = 10;
				L0006 a(s, r, ans, show);
				assert(ans == "L  t uoauhi  tm t tneasnoemhd inworhlessbtemdnt,I oo.,bsopo oa hnntesacnwateemee  wlmu s   nehsne d suireud  aw  irereg disheh mp y ryttseihepdkleAethyttltng taopde ,ewtt wselt leraAthgw eiaie m  ,s oheedh np,tyo  i h heeool en rth weawfrmorn  f eh nef,u tegatnwaeaddnru-vt.o t,ol aefocaiwere wea o sfuaa syosmleg  f  iykf rrsw   m r hwohn n s l i r ty.N olre-i btaleohul iladeteye mte,d,olognssr c  nul odlnnln wsund");
		}

}

/*----------------------------------------------------------------
main
---------------------------------------------------------------- - */
int main() {
#ifdef _WIN32
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
		L0006test a;
		return 0;
}