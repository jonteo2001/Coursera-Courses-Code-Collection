/*
MILES ARE CONVERTED TO KM
JON TEO
OCT 2020
FIRST USE OF C++
firstprog.cpp
*/

#include <iostream> //where you find the io that is adopted in C++
using namespace ::std; //think of your typedef
//if you intend to use a library and everything is prefaced by std
//then using namespace lets you avoid the std

//MAIN point of C++ was to avoid using #DEFINE , because they were preprocessor ideas
//and they were errorful in C.
const double m_to_k = 1.609; // type const - tell your prog this value doesn't change

inline double convert (int mi) {return (mi * m_to_k);}
//keyword inline: which tells the compiler to optimise a function
//allows you to save on the function call (whatever that means)
int main (void)
{
  int miles = 1; // you can put code immediately before you use it.
  while (miles != 0)
  {
    cout << "Input distance in miles or 0 to terminate: ";
    cin >> miles;
    cout<< "\n Distance is" << convert(miles) << " km." << endl;
  }
  cout << endl;
  return (0);
}

//HOW TO COMPILE: g++ firstprog.exe
