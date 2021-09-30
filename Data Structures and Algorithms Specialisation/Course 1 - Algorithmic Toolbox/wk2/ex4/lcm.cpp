#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
long long lcm_fast(long long a, long long b)
{
    if (a > b) {return lcm_fast(b, a);}
    long long common = b;
    while (common % a != 0)
    {
        common = common + b;
    }
    return common;
}
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}

