#include <iostream>
#include <string>
#include <vector>

using std::string;
using namespace std;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}
void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}
//Function to create the polynomial hash
ull hashfunc(string s, ull p, ull x)
{
    ull hash = 0;
    for (ull i = s.length()-1; i >= 0; i--)
    {
        hash = (hash * x + s[i]) % p;
    }
    return hash;
}
vector<ull> PrecomputeHashes(string text, int pattern_length, ull p, ull x)
{
    int text_length = static_cast<int>(text.length());
    vector<ull> hashvals(text_length - pattern_length + 1);
    //Create the last substring
    string last_substring = text.substr(text_length-pattern_length-1,
                                           pattern_length);
    //Calculate index for last substring
    hashvals[text_length - pattern_length] = hashfunc(last_substring, p, x);
    ull y = 1;
    for (ull i = 1; i < pattern_length; i++)
    {
        y = (y*x) % p;
    }
    for (ull i = text_length-pattern_length-1; i >=0; i--)
    {
        hashvals[i] = (x * hashvals[i+1] + text[i] - (y * text[i + pattern_length])) % p;
    }
    return hashvals;
}
//Function to see if 2 strings are equal
bool AreEqual(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    for (size_t i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}
std::vector<int> get_occurrences(const Data& input) {
    /*const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    for (size_t i = 0; i + s.size() <= t.size(); ++i)
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    return ans;*/
    // p needs to be greater than |T|*|P|.
    ull p = 100529784361;// any big prime >=10^12
    ull x = 3311944;
    vector<int> result;
    ull pHash = hashfunc(input.pattern, p, x);
    vector<ull>hashvals = PrecomputeHashes(input.text, input.pattern.length(),p, x);
    for (size_t i = 0; i <=input.text.length()- input.pattern.length(); i++)
    {
        if (pHash != hashvals[i])
            continue;
        if (AreEqual(input.text.substr(i, i+input.pattern.length()), input.pattern))
        {
            result.push_back(i);
        }
    }
    return result;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
