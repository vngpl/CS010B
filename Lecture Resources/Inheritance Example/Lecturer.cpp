#include <iostream>
#include <iomanip>

using namespace std;

#include "Lecturer.h"

//Implement Lecturer constructor
Lecturer::Lecturer(const string &name, 
                    const string &addr, 
                    const string &email, 
                    const string &eid, 
                    double courseRate, 
                    double emplPerc)
 : Employee(name, addr, email, eid),
   courseRate(courseRate), emplPerc(emplPerc)
{}

double Lecturer::getCourseRate() const {
    return courseRate;
}

double Lecturer::getEmplPerc() const {
    return emplPerc;
}

void Lecturer::setCourseRate(double courseRate) {
    this->courseRate = courseRate;
}

void Lecturer::setEmplPerc(double emplPerc) {
    this->emplPerc = emplPerc;
}

double Lecturer::paycheckAmt() const {
    return courseRate * emplPerc / 12 * 9;
}


void Lecturer::display() const {
    this->Employee::display();
    cout << "Course Rate: $" << courseRate << endl
         << "Employment %: " << emplPerc * 100 << '%' << endl;
}
