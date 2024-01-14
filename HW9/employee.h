//
// Created by 81516 on 2023/11/19.
//

#include <cstring>
#include <iostream>
using namespace std;

class employee {
public:
    friend std::ostream& operator<<(std::ostream& os, const employee& e) {
        e.print(os);  // 调用一个虚拟函数来输出
        return os;
    }
protected:
    std::string* firstName;
    std::string* lastName;
    std::string* socialSecurityNumber;
    virtual void print(std::ostream& os) const {
        os << *firstName << " " << *lastName << " " << *socialSecurityNumber;
    }
    virtual std::string getAdditionalInfo() const {
        // 基类没有额外信息
        return "";
    }
    virtual void printAssignmentInfo(const employee& other) const {
        if (show) {
            cout << "In employee equal constructor " << *firstName << " " << *lastName << " " << *socialSecurityNumber;
            cout << getAdditionalInfo() << endl; // 添加额外信息
        }
    }



public:
    static bool show; // Static member to control debug print statements

    employee(const std::string& fn, const std::string& ln, const std::string& ssn)
            : firstName(new std::string(fn)), lastName(new std::string(ln)), socialSecurityNumber(new std::string(ssn)) {
        if (show) {
            cout << "In employee::employee constructor " << *firstName << " " << *lastName << " " <<*socialSecurityNumber<< endl;
        }
    }

    employee(const employee& other)
            : firstName(new std::string(*other.firstName)), lastName(new std::string(*other.lastName)), socialSecurityNumber(new std::string(*other.socialSecurityNumber)) {
        if (show) {
            cout << "In employee copy constructor " << *firstName << " " << *lastName << " " <<*socialSecurityNumber<< endl;
        }
    }

    virtual void assign(const employee& other) {
        // 基类赋值逻辑
        *firstName = *other.firstName;
        *lastName = *other.lastName;
        *socialSecurityNumber = *other.socialSecurityNumber;
        employee::printAssignmentInfo(other);
    }

    employee& operator=(const employee& other) {
        if (this != &other) {
            assign(other);
        }
        return *this;
    }

    virtual ~employee() {
        if (show) {
            cout << "In employee::~employee distructor " << *firstName << " " << *lastName << " " <<*socialSecurityNumber<< endl;
        }
        delete(firstName);
        delete(lastName);
        delete(socialSecurityNumber);
    }


    static void setShow(bool s) {
        show = s;
    }
};

bool employee::show = false;


