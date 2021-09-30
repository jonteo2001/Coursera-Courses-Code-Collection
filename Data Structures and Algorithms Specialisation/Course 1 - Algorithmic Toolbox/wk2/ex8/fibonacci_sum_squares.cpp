#include <iostream>
using namespace std;
//The sum of the squares of consecutive fib numbers is the value of (F_n)*(Fn+Fn-1) = Fn*Fn+1
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}
int fibonacci_last_digit_fast(long long n)
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
int fibonacci_sum_squares_fast(long long n)
{
    int horizontal = fibonacci_last_digit_fast(n+1);
    int vertical = fibonacci_last_digit_fast(n);
    return ((horizontal*vertical)%10);
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n) <<endl;
}
