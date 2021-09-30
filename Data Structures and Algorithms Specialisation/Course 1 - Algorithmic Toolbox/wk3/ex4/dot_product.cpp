#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//Using global variable result
const int MIN = -1000000;
long long result2 = 0;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
    //Sort the 2 vectors in descending order
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    long long result = 0;
    for (size_t i = 0; i < a.size(); i++) {
        result += ((long long) a[i]) * b[i];
    }
  return result;
}
/*long long max_dot_product2(vector<int> a, vector<int> b)
{
    int max_a = MIN, index_a = -1;
    int max_b = MIN, index_b = -1;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > max_a) {max_a = a[i]; index_a = i;}
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] > max_a) {max_b = b[i]; index_b = i;}
    }
    long long pdt = static_cast<long long> (max_a * max_b);
    result2 = result2 + pdt;
    //Erase these 2 values from the vector
    a.erase(a.begin() + index_a);
    b.erase(b.begin() + index_b);
    if (!a.empty() && !b.empty()){return max_dot_product2(a,b);}
    return result2;
}*/
/*void informalTests()
{
    while (true)
    {
        result2 = 0;
        int n = rand()%1000+1;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            a.push_back((rand()% 200000)-100000);
            b.push_back((rand()% 200000)-100000);
        }
        long long test1 = max_dot_product(a,b);
        //long long test2 = max_dot_product2(a,b);
        cout << "n = " << n << ", Test1 = " << test1 <<endl;
    }
}*/
int main() {
    //informalTests();
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
