#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int numerator); 
      Rational(int numerator, int denominator); 
      Rational add(const Rational &explicitRationalB) const; 
      Rational subtract(const Rational &explicitRationalB) const; 
      Rational multiply(const Rational &explicitRationalB) const; 
      Rational divide(const Rational &explicitRationalB) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here

   // Rational::Rational() : numerator(0),  denominator(1) {}
   // Rational::Rational(int userNumerator) : numerator(userNumerator), denominator(1) {}
   // Rational::Rational(int userNumerator, int userDenominator) : numerator(userNumerator), denominator(userDenominator) {}

Rational::Rational() {
   this->numerator = 0;
   this->denominator = 1;
}
Rational::Rational(int userNumerator) {
   this->numerator = userNumerator;
   this->denominator = 1;
}
Rational::Rational(int userNumerator, int userDenominator) {
   this->numerator = userNumerator;
   this->denominator = userDenominator;
}

// Member function definitions

   // Rational "A" (a/b)= Implicit Parameter (this->)
   // Rational "B" (c/d)= Explicit Parameter (explicitRationalB)

Rational Rational::add(const Rational &explicitRationalB) const {
   // ((a * d) + (b * c)) / (b * d)
   int addedNumerator = (this->numerator * explicitRationalB.denominator) + (this->denominator * explicitRationalB.numerator);
   int addedDenominator = (this->denominator * explicitRationalB.denominator);
   return Rational(addedNumerator, addedDenominator);
}
Rational Rational::subtract(const Rational &explicitRationalB) const {
   // ((a * d) - (b * c)) / (b * d)
   int subtractedNumerator = (this->numerator * explicitRationalB.denominator) - (this->denominator * explicitRationalB.numerator);
   int subtractedDenominator = (this->denominator * explicitRationalB.denominator);
   return Rational(subtractedNumerator, subtractedDenominator);
}
Rational Rational::multiply(const Rational &explicitRationalB) const {
   // (a * c) / (b * d)
   int multipliedNumerator = (this->numerator * explicitRationalB.numerator);
   int multipliedDenominator = (this->denominator * explicitRationalB.denominator);
   return Rational(multipliedNumerator, multipliedDenominator);
}
Rational Rational::divide(const Rational &explicitRationalB) const {
   // (a * d) / (c * b)
   int dividedNumerator = (this->numerator * explicitRationalB.denominator);
   int dividedDenominator = (this->denominator * explicitRationalB.numerator);
   return Rational(dividedNumerator, dividedDenominator);
}
void Rational::simplify() {
   int gcdValue = gcd(this->numerator, this->denominator);
   this->numerator /= gcdValue;
   this->denominator /= gcdValue;
}
void Rational::display() const {
   cout << this->numerator << " / " << this->denominator;
}
int Rational::gcd(int numA, int numB) const {
   while (numA != numB) {
      if (numB > numA) {
         numB -= numA;
      } else {
         numA -= numB;
      }
   }
   return numA;
}


// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

