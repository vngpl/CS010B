#include <string>

using namespace std;

#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

class Employee {

  private:
    string name;
    string addr;
    string email;
    const string eid;

  public:
    Employee(const string &, const string &, const string &, const string &);
    const string & getName() const;
    const string & getAddr() const;
    const string & getEmail() const;
    const string & getEid() const;
    void setName(const string &);
    void setAddr(const string &);
    void setEmail(const string &);
    virtual void display() const = 0;
    virtual double paycheckAmt() const = 0;
};

#endif

