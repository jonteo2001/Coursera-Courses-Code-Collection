#include <iostream>
#include <cmath>
using namespace std;

//Use to check if the number can be expressed in the form of
//given a number n, output a pair of 2 integers such that 1 integer
pair<long, long> sumConsecNums(long n)
{
    pair<long, long> result;
    //Find the largest k such that (k)(k+1)/2 >= n, so k >= -1+sqrt(1+8n)/2 (via quadratic formula)
    long k = floor((-1 + sqrt(1+8*n))/2);
    
    result.first = k;
    result.second = n - (k)*(k+1)/2;
    return result;
}
int main() {
    long n;
  std::cin >> n;
  pair<long,long> k_diff = sumConsecNums(n);
    //So output 1 to the value of k, increment the last variable by the difference in the pair.
    cout << k_diff.first << endl;
    long i = 1;
    while (i < k_diff.first)
    {
        cout << i << " ";
        i = i + 1;
    }//breaks out the loop when i == k
    cout << k_diff.first + k_diff.second << endl;
    return 0;
}
