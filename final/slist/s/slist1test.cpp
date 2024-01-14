/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
Filename: slist1test.cpp
compile: g++ slist1.cpp slist1test.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
                  NOTHING CAN BE CHANGED BELOW
           No grade will be given if U change anything below
-----------------------------------------------------------------*/
#include <crtdbg.h>
#include "slist1.h"

class slist1Test {
public:
  slist1Test() {
    basic_();
    real_exam_();
  }

private:
  int marks_ = 0;
  void basic_();
  void real_exam_();
  void test1_();
  void test2_();
  void test3_();
  void build_slist_and_test_basic_(slist1& s, const T a[], int l);
  void test_delete_(int n);
  void can_you_pass_this_();
};

/*----------------------------------------------------------------
Real exam
-----------------------------------------------------------------*/
void slist1Test::real_exam_() {
  test1_();
  test2_();
  test3_();
  can_you_pass_this_();
  cout << "You got " << marks_ << " marks now\n";
}

/*----------------------------------------------------------------
all code that has to be written
-----------------------------------------------------------------*/
void slist1Test::basic_() {
  slist1 s;
  int N = 8;
  cout << "----------Testing append. MUST BE O(1) for 100 marks -------------------\n";
  for (int i = 0; i < N; ++i) {
    //Must be O(1) for fill grade
    s.append(i);
  }
  cout << "----------Testing prepend. MUST BE O(1) for 100 marks -------------------\n";
  for (int i = 0; i < N; ++i) {
    //Must be O(1) for fill grade
    s.prepend(-i);
  }
  cout << "----------Testing size ----------------\n";
  int n = s.size();
  assert(n == 2 * N);
  cout << "----------Testing cout ----------------\n";
  cout << s << endl;
  cout << "----------Testing a[i] ----------------\n";
  for (int i = 0; i < (N * 2); ++i) {
    const T* p = s[i];
    const T& v = *(p);
    cout << "a[" << i << "]= " << v << endl;
  }
  cout << "----------Testing a[i] out of bounds ----------------\n";
  {
    int pos = 20;
    {
      const T* p = s[pos];
      if (!(p)) {
        cout << "Cannot access a[" << pos << "]\n";
      }
    }
    pos = -1;
    {
      const T* p = s[pos];
      if (!(p)) {
        cout << "Cannot access a[" << pos << "]\n";
      }
    }
  }
  cout << "--------- Find and  Remove -------------------------- \n";
  {
    bool x = s.find(5);
    assert(x);
    x = s.find(-25);
    assert(!x);
    x = s.remove(5);
    assert(x);
    x = s.remove(5);
    assert(!x);
  }
  cout << "----------Testing 1)copy 2)equal 3)== 4)!== 5)conversion function () -------------------\n";
  {
    slist1 s1(s);
    s = s1;
    assert(s == s1);
    s1.append(420);
    assert(s != s1);
    assert(s1);
    slist1 s2;
    assert(!s2);
  }
  cout << "YOU PASSED BASIC TESTS. I will make you suffer in real tests\n";
  cout << "YOU may not get 60. So switch to plan B now\n";
}

/*----------------------------------------------------------------
Testing append prepend cout and s[i] - 33 marks
-----------------------------------------------------------------*/
void slist1Test::test1_() {
  cout << "-----------Testing append prepend cout and s[i] - 25 marks-------- \n";
  const T a[] = { 1,2,3,4,5 };
  int l = sizeof(a) / sizeof(T);
  slist1 s;
  build_slist_and_test_basic_(s, a, l);
  marks_ = marks_ + 25;
  cout << "You got " << marks_ << " marks now\n";
}

/*----------------------------------------------------------------
Testing copy, equal on slist
-----------------------------------------------------------------*/
void slist1Test::test2_() {
  cout << "-----------Testing copy, equal on slist - 25 marks-------- \n";
  const T a[] = { 1,2,3,4,5 };
  int l = sizeof(a) / sizeof(T);
  slist1 s1;
  for (const T& d : a) {
    s1.prepend(d);
  }
  int s1size = s1.size();
  if (s1size != l) {
    cout << "Your slist has " << s1size << " elements but it should have " << l << " elements" << endl;
    assert(l == s1size);
  }
  cout << s1 << endl;

  slist1 s2;
  for (const T& d : a) {
    s2.append(d);
  }
  int s2size = s2.size();
  if (s2size != l) {
    cout << "Your slist has " << s2size << " elements but it should have " << l << " elements" << endl;
    assert(l == s2size);
  }
  cout << s2 << endl;

  bool x = (s1 != s2);
  if (!x) {
    cout << s1 << endl;
    cout << s2 << endl;
    cout << "How they are same\n";
    assert(false);
  }

  slist1 s3(s1);
  int s3size = s3.size();
  if (s3size != l) {
    cout << "Your slist has " << s3size << " elements but it should have " << l << " elements" << endl;
    assert(l == s3size);
  }
  cout << s3 << endl;

  slist1 s4(s2);
  int s4size = s4.size();
  if (s4size != l) {
    cout << "Your slist has " << s4size << " elements but it should have " << l << " elements" << endl;
    assert(l == s4size);
  }
  cout << s4 << endl;
  s4 = s3 = s2 = s2 = s2 = s1;
  cout << s4 << endl;
  x = ((s1 == s2) && (s1 == s3) && (s1 == s4));
  if (!x) {
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << "All above must be same\n";
    assert(false);
  }

  marks_ = marks_ + 25;
  cout << "You got " << marks_ << " marks now\n";
}

/*----------------------------------------------------------------
Testing find and delete on slist
-----------------------------------------------------------------*/
void slist1Test::test3_() {
  cout << "-----------Testing find and delete - 25 marks-------- \n";
  const T a[] = { 1,2,3,4,5 };
  int l = sizeof(a) / sizeof(T);
  slist1 s1;
  for (const T& d : a) {
    s1.prepend(d);
  }
  int s1size = s1.size();
  if (s1size != l) {
    cout << "Your slist has " << s1size << " elements but it should have " << l << " elements" << endl;
    assert(l == s1size);
  }
  cout << s1 << endl;

  slist1 s2;
  for (const T& d : a) {
    s2.append(d);
  }
  int s2size = s2.size();
  if (s2size != l) {
    cout << "Your slist has " << s2size << " elements but it should have " << l << " elements" << endl;
    assert(l == s2size);
  }
  cout << s2 << endl;
  bool x = (s1 != s2);
  if (!x) {
    cout << s1 << endl;
    cout << s2 << endl;
    cout << "How they are same\n";
    assert(false);
  }
  s1 = s2;
  x = (s1 == s2);
  if (!x) {
    cout << s1 << endl;
    cout << s2 << endl;
    cout << "How they are NOT same\n";
    assert(false);
  }
  cout << s1 << endl;
  cout << s2 << endl;
  for (const T& d : a) {
    bool x = s1.find(d);
    if (!x) {
      cout << "Why " << d << " is Not there in s1 " << endl;
      assert(false);
    }
    x = s2.find(d);
    if (!x) {
      cout << "Why " << d << " is Not there in s2 " << endl;
      assert(false);
    }
  }
  {
    T d(100);
    bool x = s1.find(d);
    if (x) {
      cout << "Why " << d << " is there in s1 " << endl;
      assert(false);
    }
  }

  {
    T d(1);
    bool x = s1.remove(d);
    cout << s1 << endl;
    if (!x) {
      cout << "Why " << d << " is Not removed from s1 " << endl;
      assert(false);
    }
    for (int i = 1; i < l; ++i) {
      const T* p = s1[i - 1];
      const T& v = *(p);
      const T& e = a[i];
      if (v != e) {
        cout << "Correct s1[" << i << "]= " << e << endl;
        cout << "Yours   s1[" << i << "]= " << v << endl;
        assert(false);
      }
    }
  }
  {
    T d(5);
    bool x = s1.remove(d);
    cout << s1 << endl;
    if (!x) {
      cout << "Why " << d << " is Not removed from s1 " << endl;
      assert(false);
    }
    for (int i = 1; i < l - 1; ++i) {
      const T* p = s1[i - 1];
      const T& v = *(p);
      const T& e = a[i];
      if (v != e) {
        cout << "Correct s1[" << i << "]= " << e << endl;
        cout << "Yours   s1[" << i << "]= " << v << endl;
        assert(false);
      }
    }
  }
  {
    cout << s1 << endl;
    cout << s2 << endl;
    bool x = (s1 != s2);
    if (!x) {
      cout << "How are they same?. You cheated me in copy constructor\n";
      assert(false);
    }
  }
  {
    int n = 100;
    test_delete_(n);
    n = 1001;
    test_delete_(n);
  }

  marks_ = marks_ + 25;
  cout << "You got " << marks_ << " marks now\n";
}

/*----------------------------------------------------------------
Testing find and delete on slist in arbitrary position
-----------------------------------------------------------------*/
void slist1Test::test_delete_(int n) {
  cout << "-----------test_delete-- " << n << endl;
  slist1 s;
  for (int i = 0; i < n; ++i) {
    s.prepend(2 * i - 21);
  }

  while (s) {
    {
      int i = 0;
      int j = s.size();
      int m = (i + j) / 2;
      const T* p = s[m];
      if (p) {
        const T& v = *(p);
        s.remove(v);
      }
    }
    {
      int i = 0;
      const T* p = s[i];
      if (p) {
        const T& v = *(p);
        s.remove(v);
      }
    }
    {
      int j = s.size();
      const T* p = s[j - 1];
      if (p) {
        const T& v = *(p);
        s.remove(v);
      }
    }

  }
}

/*----------------------------------------------------------------
const T a[] = { 1,2,3,4,5 };
1->2->3->4->5->null
-----------------------------------------------------------------*/
void slist1Test::build_slist_and_test_basic_(slist1& s, const T a[], int l) {
  for (int i = 0; i < l; ++i) {
    s.append(a[i]);
  }
  int n = s.size();
  int t = l;
  if (n != t) {
    cout << "Your slist has " << n << " elements but it should have " << t << " elements" << endl;
    assert(n == t);
  }
  cout << s << endl;
  for (int i = 0; i < l; ++i) {
    s.prepend(a[i]);
  }
  t = l + l;
  n = s.size();
  if (n != t) {
    cout << "Your slist has " << n << " elements but it should have " << t << " elements" << endl;
    assert(n == t);
  }
  cout << s << endl;
  for (int i = 0; i < l; ++i) {
    const T* p = s[i];
    const T& v = *(p);
    const T& e = a[l - 1 - i];
    if (v != e) {
      cout << "Correct slist1[" << i << "]= " << e << endl;
      cout << "Yours   slist1[" << i << "]= " << v << endl;
      assert(false);
    }
  }
  assert(s[t] == nullptr);
  assert(s[-1] == nullptr);
  for (int i = 0; i < l; ++i) {
    const T* p = s[i + l];
    const T& v = *(p);
    const T& e = a[i];
    if (v != e) {
      cout << "Correct slist1[" << i << "]= " << e << endl;
      cout << "Yours   slist1[" << i << "]= " << v << endl;
      assert(false);
    }
  }
  assert(s[t] == nullptr);
  assert(s[-1] == nullptr);

}

/*----------------------------------------------------------------
What happend
-----------------------------------------------------------------*/
void slist1Test::can_you_pass_this_() {
  cout << "Let us see how you will get 25 marks more\n";
  int N = 1000000;
  slist1 s;
  for (int i = 0; i < N; ++i) {
    s.append(i);
  }
  for (int i = 0; i < N; ++i) {
    s.prepend(i);
  }
  marks_ = marks_ + 25;
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  slist1Test h = slist1Test();

  cout << "for 100 marks, there should be no memory leaks here \n";
  cout << "Only UPLOAD slist1.cpp  slist1.h in Canvas. NO ZIP FILE\n";
  cout << "DO NOT UPLOAD slist1test.cpp to Canvas\n";
  cout << "We will run with master slist1test.cpp and all tests must pass\n";
}

