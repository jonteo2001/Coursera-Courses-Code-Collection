#include <iostream>
/*
 From the previous example ex5, we can calculate the length of the sequence Fn mod (10), and we get a sequence of length 60. By running the function for modulo 10, we get a sequence:
 int preparedNumbers[kPisanoSize] = {0, 1, 2, 4, 7, 2, 0, 3, 4, 8, 3,
         2, 6, 9, 6, 6, 3, 0, 4, 5, 0, 6, 7, 4, 2, 7, 0, 8, 9, 8, 8, 7,
         6, 4, 1, 6, 8, 5, 4, 0, 5, 6, 2, 9, 2, 2, 5, 8, 4, 3, 8, 2, 1,
         4, 6, 1, 8, 0, 9, 0};
 Sum of these numbers is 260 modulo 10 which is congruent to 0.
 This means that the last digit of the sum is to take n modulo 60, and sum the terms up to but not including that result.
 */
using namespace std;
int fibonacci_sum_fast(long long n)
{
    int sequence[60] = {0, 1, 2, 4, 7, 2, 0, 3, 4, 8, 3,
            2, 6, 9, 6, 6, 3, 0, 4, 5, 0, 6, 7, 4, 2, 7, 0, 8, 9, 8, 8, 7, 6, 4, 1, 6, 8, 5, 4, 0, 5, 6, 2, 9, 2, 2, 5, 8, 4, 3, 8, 2, 1, 4, 6, 1, 8, 0, 9, 0};
    /*
    int sum = 0; long long i = 0;
    for(int i = 0; i <=n; i++)
    {
        sum = (sum + sequence[i%60])%10;
    }
    return sum;
    */
    int sum = 0;
    for (int i = 0; i < 60; i++)
    {
        sum = (sum + sequence[i])%10;
        sequence[i] = sum;
        printf("%d, ", sequence[i]);
    }
    return sum;
}
int main() {
    long long n;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n)<<endl;
    return 0;
}
//Run time = 3* O(n) = O(n) time
