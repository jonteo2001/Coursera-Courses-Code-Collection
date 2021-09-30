#include <iostream>
#include <cmath>
using namespace std;
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int fibonacci_last_digit_fast(int n)
{
    if (n <=1) { return n;}
    int count = 2;
    int *fibprev = new int(1);
    int *fibprev2 = new int(0);
    int *fib = new int();
    while (count < n+1)
    {
        *fib = (*fibprev + *fibprev2)%10;
        if(count + 1 < n+1)
        {
            *fibprev2 = *fibprev;
            *fibprev = *fib;
        }
        count++;
    }
    return *fib;
}
bool informalTests()
{
    for (int i =0; i < 40; i++)
    {
        if(get_fibonacci_last_digit_naive(i) != fibonacci_last_digit_fast(i))
        {
            cout<< "Wrong Answer: \n" << "n = " << i << "\n"
            << get_fibonacci_last_digit_naive(i) << " | "
            << fibonacci_last_digit_fast(i) << "\n"
            << "Program is still buggy."
            << endl; return false;
        }
        else{ cout << "n = "<< i << " - OK" <<endl;}
    }
    cout << "Program is ok. Enter integer n to continue: \n "<< endl;
    return true;
}
int main() {
   // bool test = informalTests();
   // if (test == false) {return -1;}
    int n;
    std::cin >> n;
    int c = fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    return 0;
    }
