#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
/*
 
 Problem Introduction
 The edit distance between two strings is the minimum number of operations (insertions, deletions, and substitutions of symbols) to transform one string into another. It is a measure of similarity of two strings. Edit distance has applications, for example, in computational biology, natural language processing, and spell checking. Your goal in this problem is to compute the edit distance between two strings.
 
 Problem Description
 Task. The goal of this problem is to implement the algorithm for computing the edit distance between two strings.
 Input Format. Each of the two lines of the input contains a string consisting of lower case latin letters. Constraints. The length of both strings is at least 1 and at most 100.
 Output Format. Output the edit distance between the given two strings.
 
 */
const int INF = 999;
int edit_distance(const string &str1, const string &str2) {
  //write your code here
    /*The last common of an optimal alignment is either:
     - An insertion
     - A Deletion
     - A Mismatch
     - A Match
     */
   // Create n+1 by m+1 matrix D
    vector<int> cols(str2.length()+1, INF);
    vector<int> rows(str1.length()+1, INF);
    vector< vector<int> > D(rows.size(), cols);
    //Initialise all the values with at least 1 index with 0.
    for (int i = 0; i < rows.size(); i++){D[i][0] = i;}
    for (int j = 0; j < cols.size(); j++){D[0][j] = j;}
    //Now fill the rest of the matrix D with values
    for (int j = 1; j < cols.size(); j++)
    {
        for (int i = 1; i < rows.size(); i++)
        {
            int insert = D[i][j-1] + 1;
            int del = D[i-1][j] + 1;
            if (str1[i-1] == str2[j-1])
            {
                //cout << str1[i-1] << " " << str2[j-1] << endl;
                int match = D[i-1][j-1];
                vector<int> list; list.push_back(insert); list.push_back(del); list.push_back(match);
                sort(list.begin(), list.end());
                D[i][j] = list[0];
                //cout << "D["<<i<<"]["<<j<<"]=" << D[i][j] << endl;
                list.clear();
            }
            else
            {
                //cout << str1[i-1] << " " << str2[j-1] << endl;
                int mismatch = D[i-1][j-1]+1;
                vector<int> list; list.push_back(insert); list.push_back( del), list.push_back(mismatch);
                sort(list.begin(), list.end());
                D[i][j] = list[0];
                //cout << "D["<<i<<"]["<<j<<"]=" << D[i][j] << endl;
                list.clear();
            }
        }
    }
    //cout << cols.size() <<" " << rows.size() <<endl;
    return D[rows.size()-1][cols.size()-1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
