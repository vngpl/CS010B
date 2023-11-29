#include "Distance.h"

Distance::Distance() {
    _feet = 0;
    _inches = 0.0;
}

Distance::Distance(unsigned ft, double in) {
    _feet = ft;
    _inches = in;
    init();
}

Distance::Distance(double in) {
    _feet = 0;
    _inches = in;
    init();
}

unsigned Distance::getFeet() const {
    return _feet;
}

double Distance::getInches() const {
    return _inches;
}

double Distance::distanceInInches() const {
    double feetToInch = _feet * 12;
    double totalInches = feetToInch + _inches;
    return totalInches;
}

double Distance::distanceInFeet() const {
    double inchToFeet = _inches / 12;
    double totalFeet = inchToFeet + _feet;
    return totalFeet;
}

double Distance::distanceInMeters() const {
    // 1 inch = 0.0254 meters
    double conversionFactor_inchToMeter = 0.0254;
    double totalMeters = distanceInInches() * conversionFactor_inchToMeter;
    return totalMeters;
}

Distance Distance::operator+(const Distance &rhs) const {
    int totFeet = _feet + rhs._feet;
    double totInches = _inches + rhs._inches;
    return Distance(totFeet, totInches);
}

Distance Distance::operator-(const Distance &rhs) const {
    double totalInches = distanceInInches() - rhs.distanceInInches();
    return Distance(totalInches);
}

ostream & operator<<(ostream &out, const Distance &rhs) {
    out << rhs.getFeet() << "' " << rhs.getInches() << "\"";
    return out;
}

void Distance::init() {
    while (_inches < 0) {
        _inches = -_inches;
    }
    
    while (_inches >= 12) {
        _feet++;
        _inches -= 12;
    }
}

