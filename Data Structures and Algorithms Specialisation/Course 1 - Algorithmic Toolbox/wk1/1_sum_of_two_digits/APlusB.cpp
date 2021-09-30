#include <iostream>
using namespace std;
int addtwodigits(int first, int second){return (first + second);}
int main ()
{
    int a,b;
    cin >> a >> b;
    cout << addtwodigits(a,b) << endl;
    return 0;
}
