/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: composition.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
only includes here
-----------------------------------------------------------------*/
#include "composition.h"


#ifdef RAWPOINTER
// Constructor
mstring::mstring(const char* str) : s_(new string(str)) {
  cout << "in mstring constructor " << *s_ << endl;
}

// Destructor
mstring::~mstring() {
  cout << "in mstring distructor " << *s_ << endl;
  delete s_;
}

// Copy constructor
mstring::mstring(const mstring& other) : s_(new string(*other.s_)) {
  cout << "in mstring copy constructor " << *s_ << endl;
}

// Copy assignment operator
mstring& mstring::operator=(const mstring& other) {
  if (this != &other) {
    delete s_;
    s_ = new string(*other.s_);
    cout << "in mstring equal operator " << *s_ << endl;
  }
  return *this;
}


#endif

#ifdef UNIQUEPOINTER
// Constructor
mstring::mstring(const char* str) : s_(std::make_unique<string>(str)) {
    cout << "in mstring constructor " << *s_ << endl;
}

// Destructor
mstring::~mstring() {
    if (s_) {
        cout << "in mstring distructor " << *s_ << endl;
    } else {
        cout << "in mstring distructor, string is already moved" << endl;
    }
}

mstring::mstring(const mstring& other) : s_(std::make_unique<string>(*other.s_)) {
    cout << "in mstring copy constructor " << *s_ << endl;
}

mstring& mstring::operator=(const mstring& other) {
    if (this != &other) {
        s_ = std::make_unique<string>(*other.s_);
        cout << "in mstring equal operator " << *s_ << endl;
    }
    return *this;
}

// 移动构造函数
mstring::mstring(mstring&& other) noexcept : s_(std::move(other.s_)) {
    cout << "in mstring copy constructor " << (s_ ? *s_ : "moved") << endl;
}

// 移动赋值运算符
mstring& mstring::operator=(mstring&& other) noexcept {
    if (this != &other) {
        s_ = std::move(other.s_);
        cout << "in mstring equal operator " << (s_ ? *s_ : "moved") << endl;
    }
    return *this;
}


#endif


ssn::~ssn() {
    cout << "in ssn disstructor" << endl;
}

name::~name() {
    cout <<"in name disstructor"<< endl;
}

// ssn 构造函数
ssn::ssn(const char* s, const char* n, const char* c) : ssn_(s), name_(n), country_(c) {

    cout << "in ssn constructor" << endl;
}

// ssn 复制构造函数
ssn::ssn(const ssn& other)
#ifdef RAWPOINTER
: ssn_(other.ssn_), name_(other.name_), country_(other.country_) {
#endif
#ifdef UNIQUEPOINTER
        : ssn_(other.ssn_), name_(other.name_), country_(other.country_) {
#endif
}

// ssn 复制赋值运算符
ssn& ssn::operator=(const ssn& other) {
    if (this != &other) {
#ifdef UNIQUEPOINTER
        ssn_ = other.ssn_;
        name_ = other.name_;
        country_ = other.country_;
#endif
#ifdef RAWPOINTER
        ssn_ = other.ssn_;
        name_ = other.name_;
        country_ = other.country_;
#endif
    }
    return *this;
}


// ssn operator<< 重载
ostream& operator<<(ostream& os, const ssn& obj) {
    os << obj.name_.str() << " " << obj.ssn_.str() << " " << obj.country_.str();
    return os;
}

// name 构造函数
name::name(const char* f, const char* l, const char* m, const char* t)
        : fname_(f), lname_(l ? l : ""), mname_(m ? m : ""), title_(t ? t : "") {
    cout << "in name constructor" << endl;
}


name::name(const name& other)
#ifdef UNIQUEPOINTER
        : fname_(other.fname_), lname_(other.lname_), mname_(other.mname_), title_(other.title_)
#endif
#ifdef RAWPOINTER
: fname_(other.fname_), lname_(other.lname_), mname_(other.mname_), title_(other.title_)
#endif
{
}

name& name::operator=(const name& other) {
    if (this != &other) {
#ifdef UNIQUEPOINTER
        fname_ = mstring(other.fname_.str());
        lname_ = mstring(other.lname_.str());
        mname_ = mstring(other.mname_.str());
        title_ = mstring(other.title_.str());
#endif
#ifdef RAWPOINTER
        fname_ = other.fname_;
        lname_ = other.lname_;
        mname_ = other.mname_;
        title_ = other.title_;
#endif
    }
    return *this;
}

// name operator<< 重载
ostream& operator<<(ostream& os, const name& obj) {
    os << obj.title_.str()<< " " << obj.fname_.str() << " " << obj.mname_.str() << " " << obj.lname_.str() ;
    return os;
}

person::person(const ssn& ssn_obj, const name& name_obj, const dob& dob_obj,const mstring& place, bool is_alive)
    : ssn_(ssn_obj), name_(name_obj), _dob(dob_obj),_currentp_lace_of_residence(place), _isalive(is_alive) {
    cout << "in person constructor" << endl;
}

person::person(const ssn& ssn_obj, const name& name_obj, const dob& dob_obj,const mstring& place)
        : person(ssn_obj, name_obj, dob_obj, place, true) {
}

person::~person() {
    cout <<"in person disstructor"<< endl;
}

dob::dob(unsigned int month, unsigned int day, unsigned int year)
        : month_(month), day_(day), year_(year) {
    cout << "in dob constructor" << endl;
};

dob::~dob()  {
    cout <<"in dob distructor"<< endl;
}

ostream& operator<<(ostream& os, const list_of_graduates& lg) {
    for (int i = 0; i < lg.size_; ++i) {
        if (lg.list_[i] != nullptr) {
            os << *(lg.list_[i]);
            if (i < lg.size_ - 1) {
                os << endl; // 在每个graduate对象之后添加换行，除了最后一个
            }
        }
    }
    return os;
}

ostream& operator<<(ostream& os, const graduate& g) {
    const person& p = g.p_;
    os << p.name_.title_.str() << " " << p.name_.fname_.str() << " " << p.name_.mname_.str() << " " << p.name_.lname_.str() << " "
       << p.ssn_.name_.str()<< " " <<p.ssn_.ssn_.str() << " " << p.ssn_.country_.str() << " "
       << p._dob.month_ << " " << p._dob.day_ << " " << p._dob.year_ << " "
       << p._currentp_lace_of_residence.str() << " ";
    if(p._isalive==false)
       os<< "Dead"<< " ";
    os << g.degree_awarded_.str() << " " << g.year_;
    return os;
}

