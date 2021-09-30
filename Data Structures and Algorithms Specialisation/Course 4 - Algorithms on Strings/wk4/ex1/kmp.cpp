#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;

/* Prefix Function
 - Takes in a vector as an argument in place
 - Modifies the vector in place.
 - Computes the largest possible border of a given substring
 - Returns void
 */
void ComputePrefixes(vector<int>& prefixes, string &s)
{
    prefixes[0] = 0;
    int border = 0;
    for (int i = 1; i < s.length(); i++)
    {
        while (border > 0 && s[i] != s[border]) // case where it is not equal
            border = prefixes[border-1]; // reduce the size of the border until we find that prefixes[i]  == prefixes[border] for some border.
        if (s[i] == s[border]) border += 1;
        else
            border = 0;
        prefixes[i] = border;
    }
}
// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where 
// the pattern starts in the text.
vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  // Implement this function yourself
    if (pattern.length() > text.length())
    {
        return result; // sample case 1
        //empty vec
    }
    //Create the string s, where s is the concatenation of P, a random character, and T, in this order.
    string s; int P = pattern.length();
    s += pattern; s += '$'; s+=text;
    vector<int> prefix(s.length(), -1);
    ComputePrefixes(prefix, s);
    /*
    std::cout << "To debug -------" <<std::endl;
    for (int &i : prefix)
    {
        std::cout << i << " ";
    }
    std::cout<< std::endl;*/
    for (int i = P+1; i < s.length(); i++)
    {
        if (prefix[i] == P)
            result.push_back(i - 2*P);
    }
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
