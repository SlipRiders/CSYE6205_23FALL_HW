/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: L0006.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
6. Zigzag Conversion
https://leetcode.com/problems/zigzag-conversion/
---------------------------------------------------------------- - */

/*----------------------------------------------------------------
NO  includes here
CUT AND PASTE whole file in Leetcode
-----------------------------------------------------------------*/
/*----------------------------------------------------------------
WRITE CLASS L0006
-----------------------------------------------------------------*/
/*----------------------------------------------------------------
Declaration of L0006 class
-----------------------------------------------------------------*/
class L0006 {
public:
  //WRITE CODE
  L0006(const string& s, int r, string& ans, bool show) : s_(s), r_(r), ans_(ans), show_(show) {
      alg_(); // 在构造函数中调用alg_()方法
  }
private:
  //inputs
  const string& s_; 
  const int r_;
  string& ans_;
		bool show_;
  //all private routines
  void alg_();
};


/*----------------------------------------------------------------
Time: THETA(n)
Space O(n*r)
-----------------------------------------------------------------*/
void L0006::alg_() {
		//WRITE CODE
    if (r_ == 1) {
        ans_ = s_;
        return;
    }

    vector<string> rows(min(r_, int(s_.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s_) {
        rows[curRow] += c;
        if (curRow == 0 || curRow == r_ - 1) {
            goingDown = !goingDown;
        }
        curRow += goingDown ? 1 : -1;
    }

    for (string row : rows) {
        ans_ += row;
    }
}


/*----------------------------------------------------------------
Leetcode interface
NPTHING CAN BE CHANGED BELOW
This procedure must be at the end
-----------------------------------------------------------------*/
class Solution {
public:
		string convert(string s, int numRows) {
				string ans;
				bool show = false;
    L0006 a(s, numRows, ans, show);
    return ans;
  }
};

