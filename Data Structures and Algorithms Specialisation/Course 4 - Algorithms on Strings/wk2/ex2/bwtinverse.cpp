#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;

//Declare a type alias
/* BWTElem stores
 - char c,
 - index i, in the initial array, before it gets sorted.
 */
using BWTElem = pair<char, int>;

//using std::unordered_map<int, int>
//TODO: Don't be a clown. Use the First-Last property. Thanks!


/*
 First-Last Property
 • the k-th occurrence of symbol in FirstColumn
 • and the k-th occurrence of symbol in LastColumn
 • correspond to appearance of symbol at the same position in Text.
 */
string InverseBWT(const string& bwt)
{
    string text = "";

  // write your code here
    int n = bwt.length();
    vector<BWTElem> lastcol(n,make_pair('?', 0));
    for (int i = 0; i < n;i++)
    {
        lastcol[i].first = bwt[i];
        lastcol[i].second = i;
        
    }
    vector<BWTElem> firstcol = lastcol;
    sort(firstcol.begin(), firstcol.end()); // sort to obtain first col, with the index i of that of the last column.
    //Firstcol stores the index i of the last column and is sorted lexicographically
    // by the first column and secondary index of i.
    //Pass these vectors into CountOccurences to get the occurences of each letter
    //labelled.
    BWTElem iter = firstcol[0]; // initialised to the dollar sign
    for (int i = 0; i < n; i++)
    {
        //iter = lastcol[iter.second]; // go to last column
        iter = firstcol[iter.second]; /* advance from last column to first column.
                                       so instead of spelling text backward you spell it FORWARD!!
                                       smartt!
                                       */
        text+= iter.first;
    }
    
  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
