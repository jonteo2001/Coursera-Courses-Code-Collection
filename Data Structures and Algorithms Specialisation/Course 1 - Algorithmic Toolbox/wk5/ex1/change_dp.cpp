#include <iostream>
#include <vector>
using namespace std;
/*
 As we already know, a natural greedy strategy for the change problem does not work correctly for any set of denominations. For example, if the available denominations are 1, 3, and 4, the greedy algorithm will change 6 cents using three coins (4 + 1 + 1) while it can be changed using just two coins (3 + 3). Your goal now is to apply dynamic programming for solving the Money Change Problem for denominations 1, 3, and 4.
 
 Problem Description
 Input Format. Integer money.
 Output Format. The minimum number of coins with denominations 1, 3, 4 that changes money. Constraints. 1 ≤ money ≤ 10^3.
 */
const int INF = 999;
int get_change(int money)
{
  //write your code here
    vector<int> MinNumCoins(money+1, INF); // Create vector MinNumCoins set all values to infinity
    MinNumCoins[0] = 0;
    vector<int> coins; coins.push_back(1); coins.push_back(3); coins.push_back(4);
    int NumCoins;
    for (int i = 1; i <= money; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i >= coins[j])
            {
                NumCoins = MinNumCoins[i-coins[j]]+1;
                if (NumCoins < MinNumCoins[i])
                {
                    MinNumCoins[i] = NumCoins;
                }
            }
        }
    }
    return MinNumCoins[money];
}
int COIN_COUNT1 = 0;
int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
