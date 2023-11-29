#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;
   
   vector<string> months{"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

 public:
   // creates the date January 1st, 2000.
   Date();

   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);

   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);

   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;

   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;

   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};

// Implement the Date member functions here
Date::Date() {
   monthName = "January";
   month = 1;
   day = 1;
   year = 2000;
}
Date::Date(unsigned m, unsigned d, unsigned y) {
   month = m;
   monthName = name(month);
   day = d;
   year = y;

   if (month > 12) {
      month = 12;
      monthName = name(month);
   } 
   else if (month < 1) {
      month = 1;
      monthName = name(month);
   }

   if (day > daysPerMonth(month, year)) {
      day = daysPerMonth(month, year);
   }
   else if (day < 1) {
      day = 1;
   }
   if (month != m || day != d) {
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
}
Date::Date(const string &mn, unsigned d, unsigned y) {
   monthName = mn;
   month = number(monthName);
   day = d;
   year = y;

   bool invalidMonthString = true;
   string monthToUpper = "";

   for (unsigned i = 0; i < months.size(); ++i) {
      monthToUpper = months.at(i);
      monthToUpper[0] = toupper(monthToUpper[0]);
      if ((monthName == months.at(i)) || (monthName == monthToUpper)) {
         if (monthName != monthToUpper) {
            monthName = monthToUpper;
         }
         invalidMonthString = false;
         break;
      }
      else {
         invalidMonthString = true;
      }
   }

   if (invalidMonthString == true) {
      monthName = "January";
      month = 1;
      day = 1;
      year = 2000;
      cout << "Invalid month name: the Date was set to " << month << "/" << day << "/" << year << "." << endl;
   }
   else if (invalidMonthString == false) {
      if (month > 12) {
         month = 12;
      } 
      else if (month < 1) {
         month = 1;
      }

      if (day > daysPerMonth(month, year)) {
         day = daysPerMonth(month, year);
      }
      else if (day < 1) {
         day = 1;
      }
      if (day != d) {
         cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;    
      }
   }
}

void Date::printNumeric() const{
   cout << month << "/" << day << "/" << year;
}
void Date::printAlpha() const{
   cout << monthName << " " << day << ", " << year;
}

bool Date::isLeap(unsigned y) const {
   if (y % 4 == 0) {
      if ((y % 100 != 0) || (y % 400 == 0)) {
         return true;
      }
   }
   return false;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
   if ((m == 4) || (m == 6) || (m == 9) || (m == 11)) {
      return 30;
   } 
   else if ((m == 2)) {
      if (isLeap(y) == true) {
         return 29;
      }
      else {
         return 28;
      }
   } 
   else {
      return 31;
   }
}
string Date::name(unsigned m) const {
   unsigned monthNumber = 0;
   string monthToUpper = "";
   string nameOfMonth = "";

   for (unsigned i = 0; i < months.size(); ++i) {
      monthToUpper = months.at(i);
      monthToUpper[0] = toupper(monthToUpper[0]);
      monthNumber = i + 1;
      if (m == monthNumber) {
         nameOfMonth = monthToUpper;
         break;
      }
   }

   return nameOfMonth;
}
unsigned Date::number(const string &mn) const {   
   unsigned monthNumber = 0;
   string monthToUpper = "";

   for (unsigned i = 0; i < months.size(); ++i) {
      monthToUpper = months.at(i);
      monthToUpper[0] = toupper(monthToUpper[0]);
      monthNumber = i + 1;
      if ((mn == months.at(i)) || (mn == monthToUpper)) {
         break;
      }
   }

   return monthNumber;
}


// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
