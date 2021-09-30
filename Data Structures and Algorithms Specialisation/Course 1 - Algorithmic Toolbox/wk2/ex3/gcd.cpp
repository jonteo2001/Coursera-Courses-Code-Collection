#include <iostream>
#include <cstdlib>
using namespace std;
long long gcd_naive(long long a, long long b) {
 long long  current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

long long gcd_fast(long long a, long long b)
{
    if (a > b) {return gcd_fast (b, a);}
    //Now b > a, and b = b' + aq, for some positive whole number q, so:
    if (a == 0) {return b;}
    else{return gcd_fast(b%a, a);}
    
    
}
bool informalTests()
{
    long long a = rand()%20+1, b = rand()%20+1;
    for (int i = 0; i < 40; i++)
    {
        if (gcd_naive(a,b) != gcd_fast(a,b))
        {
            cout << "Wrong Answer when n = " << i<< "\n"
            << a << " | " << b << "\n"
            << gcd_naive(a,b) << " | " << gcd_fast(a,b)
            << "Program is still buggy." << endl;
            return false;
        }
        else {cout << "n = " << i << " - OK" << endl;}
    }
    return true;
}
int main() {
    //bool test = informalTests();
    //if (test == false){return (-1);}
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd_fast(a, b) << std::endl;
    return 0;
}
