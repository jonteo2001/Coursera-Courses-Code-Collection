#include <iostream>
#include <vector>
using namespace std;
/*
 Problem Introduction
 You are given a set of bars of gold and your goal is to take as much gold as possible into your bag. There is just one copy of each bar and for each bar you can either take it or not (hence you cannot take a fraction of a bar).
 Problem Description
 Task. Given 𝑛 gold bars, find the maximum weight of gold that fits into a bag of capacity 𝑊 .
 Input Format. The first line of the input contains the capacity 𝑊 of a knapsack and the number 𝑛 of bars
 of gold. The next line contains 𝑛 integers 𝑤0 , 𝑤1 , . . . , 𝑤𝑛−1 defining the weights of the bars of gold. Constraints. 1 ≤ 𝑊 ≤ 104; 1 ≤ 𝑛 ≤ 300; 0 ≤ 𝑤0,...,𝑤𝑛−1 ≤ 105.
 Output Format. Output the maximum weight of gold that fits into a knapsack of capacity 𝑊 .

 */
using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}
const int zeros = 0;
// Your code here
int optimal_weightDP(int W, const vector<int> &w)
{
    // I will write my code here
    //Creating the n x W (n rows W columns) matrix and set all values to 0
    vector<int> cols(W+1, zeros);
    vector<int> rows(w.size()+1, zeros);
    vector< vector<int> > value(rows.size(), cols);
    
    // Now iterate through the matrix
    for (int i = 1; i < rows.size(); i++)
    {
        for (int j = 1; j < cols.size(); j++)
        {
            value[i][j] = value[i-1][j];
            if (w[i-1] <= j)
            {
                int val = value[i-1][j-w[i-1]] + w[i-1];
                if (value[i][j] < val)
                {
                    value[i][j] = val;
                }
            }
        }
    }
    /* //To print out the matrix
    for (int i = 0; i < rows.size(); i++)
    {
        for (int j = 0; j < cols.size(); j++)
        {
            cout << value[i][j] << "\t";
        }
        cout << endl;
    }
     */
    //cout << "Value = " << value[rows.size()-1][W-1] << endl;
    return value[rows.size()-1][W];
}
int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weightDP(W, w) << endl;
    return 0;
}
