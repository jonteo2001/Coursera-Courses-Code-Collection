#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// This creates the matrix and sorts each element in the matrix.
string constructBWT(const string &text)
{
    vector<char> text_array(text.length());
    vector < vector<char> > BWT;
    //Separate each char into a vector
    for (int i = 0; i < text.length(); i++)
    {
        text_array[i] = text[i];
    } //O(L)
    
    for (int i = 0; i < text_array.size(); i++)
    {
        BWT.push_back(text_array);
        
        char last_char = text_array.back();
        text_array.pop_back(); // chop last element
        text_array.insert(text_array.begin(),last_char); //insert it at the front
        //repeat
    } //O(L)
    //Now sort the matrix
    std::stable_sort (BWT.begin(), BWT.end());
    //To debug -----
    /*
    cout << "To Debug --------------" << endl;
    for (vector<char>& v : BWT)
    {
        for (char &c : v)
        {
            cout << c;
        }
        cout << endl;
    }
    cout << "End Debug --------------" << endl;
     */
    //------
    // Take the last element of each vector and concatenate them together.
    string BWTstring = "";
    for (int i = 0; i < BWT.size(); i++)
    {
        char BWTchar = BWT[i].back();
        BWTstring+= BWTchar;
        
    }
    return BWTstring;
}
string BWT(const string& text) {
  string result = constructBWT(text);

  // write your code here

  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}
