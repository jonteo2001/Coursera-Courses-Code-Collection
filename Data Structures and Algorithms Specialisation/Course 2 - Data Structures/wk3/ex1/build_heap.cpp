/*
 ================ QUESTION PROMPT ===================
 Problem Introduction
 In this problem you will convert an array of integers into a heap. This is the crucial step of the sorting algorithm called HeapSort. It has guaranteed worst-case running time of 𝑂(𝑛 log 𝑛) as opposed to QuickSort’s average running time of 𝑂(𝑛 log 𝑛). QuickSort is usually used in practice, because typically it is faster, but HeapSort is used for external sort when you need to sort huge files that don’t fit into memory of your computer.
 
 Problem Description
 Task. The first step of the HeapSort algorithm is to create a heap from the array you want to sort. By the way, did you know that algorithms based on Heaps are widely used for external sort, when you need to sort huge files that don’t fit into memory of a computer?
 Your task is to implement this first step and convert a given array of integers into a heap. You will do that by applying a certain number of swaps to the array. Swap is an operation which exchanges elements 𝑎𝑖 and 𝑎𝑗 of the array 𝑎 for some 𝑖 and 𝑗. You will need to convert the array into a heap using only 𝑂(𝑛) swaps, as was described in the lectures. Note that you will need to use a min-heap instead of a max-heap in this problem.
 
 Input Format. The first line of the input contains single integer 𝑛. The next line contains 𝑛 space-separated integers 𝑎𝑖.
 
 Constraints. 1≤𝑛≤100000;0≤𝑖,𝑗≤𝑛−1;0≤𝑎0,𝑎1,...,𝑎𝑛−1 ≤109.All𝑎𝑖 aredistinct.
 
 Output Format. The first line of the output should contain single integer 𝑚 — the total number of swaps. 𝑚 must satisfy conditions 0 ≤ 𝑚 ≤ 4𝑛.
 The next 𝑚 lines should contain the swap operations used to convert the array 𝑎 into a heap.
 Each swap is described by a pair of integers 𝑖,𝑗 — the 0-based indices of the elements to be swapped.
 After applying all the swaps in the specified order the array must become a heap, that is, for each 𝑖 where 0 ≤ 𝑖 ≤ 𝑛 − 1 the following conditions must be true:
            1. If2𝑖+1≤𝑛−1,then 𝑎𝑖 <𝑎2𝑖+1.
            2. If2𝑖+2≤𝑛−1,then 𝑎𝑖 <𝑎2𝑖+2.
 Note that all the elements of the input array are distinct. Note that any sequence of swaps that has length at most 4𝑛 and after which your initial array becomes a correct heap will be graded as correct.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // for floor() function

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using namespace std;
class HeapBuilder {
 private:
    vector<int> data_;
    vector< pair<int, int> > swaps_;

    void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

    void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
    //Some utility functions for heap
    int Parent(int i) {return floor(static_cast<double>(i-1)/2);} //Returns index of parent
    int LeftChild(int i) {return (2*i + 1);} // Returns left child of parent
    int RightChild(int i) {return (2*i + 2);} // Returns right child of parent
    
    // Implement the SiftDown Function
    void SiftDown(int i)
    {
        // minindex is used to store the SMALLEST value of that subtree
        int minIndex = i;
        int leftChild = LeftChild(i);
        // If left child is smaller than the element at minIndex
        if ((leftChild < data_.size()/* zero index array*/)
            && (data_[leftChild] < data_[minIndex]))
        {
            minIndex = leftChild;
        }
        int rightChild = RightChild(i);
        if ((rightChild < data_.size()) && (data_[rightChild] < data_[minIndex]))
        {
            minIndex = rightChild;
        }
        if (i != minIndex)
        {
            swaps_.push_back(make_pair(i, minIndex)); // insert at the end of the swaps vector
            swap(data_[i], data_[minIndex]); // swap the data in place
            SiftDown(minIndex); // recursively siftdown if heap structure is still violated.
        }
    }
    // This function should accept an index as input,
    void GenerateSwaps() {
      
        swaps_.clear();
        // The following naive implementation just sorts
        // the given sequence using selection sort algorithm
        // and saves the resulting sequence of swaps.
        // This turns the given array into a heap,
        // but in the worst case gives a quadratic number of swaps.
        
        // ------ MY CODE BETWEEN THE LINES ------
        for (int i = floor(static_cast<double>(data_.size())/2); i >= 0; i--)
        {
            SiftDown(i);
        }
        
        // ---------------------------------------
        /*//
    // TODO: replace by a more efficient implementation
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }  */
      
  }
    
 public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
