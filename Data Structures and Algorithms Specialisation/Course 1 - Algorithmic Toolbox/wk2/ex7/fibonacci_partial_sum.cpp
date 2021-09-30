#include <iostream>
#include <vector>
using namespace std;
//This function computes fib value from 0 to max
vector<int> fibonacci_last_digit_fast(long long min, long long max, vector<int>& emptyvec) //Modified from wk2ex6
{
    if (max < 0) {emptyvec.push_back(-1); return emptyvec;}
    if (max == 0){emptyvec.push_back(0); return emptyvec;}
    if (max == 1){emptyvec.push_back(0); emptyvec.push_back(1); return emptyvec;}
    //n > 1
    emptyvec.push_back(0); //index 0
    emptyvec.push_back(1); //index 1
    long count = 2;
    int *fibprev = new int(1);
    int *fibprev2 = new int(0);
    int *fib = new int();
    while (count < max+1) //O(n)
    {
        *fib = (*fibprev + *fibprev2)%10;
        emptyvec.push_back(*fib);
        if(count + 1 < max+1)
        {
            *fibprev2 = *fibprev;
            *fibprev = *fib;
        }
        count++;
        
    }
    return emptyvec;
}
int fibonacci_partial_sum_fast(long long min, long long max)
{
    int sum = 0; long long i = min;
    vector<int> last_digits; // O(1) time
    last_digits = fibonacci_last_digit_fast(min, max, last_digits);
    while (i < max+1)
    {
        sum = (sum + last_digits[i])%10;
        i++;
    }
    return sum;
    
}
int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << fibonacci_partial_sum_fast(from, to) << endl;
    return 0;
}
