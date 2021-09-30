#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
using std::cin;
using std::cout;
using std:: endl;
using std::istringstream;
using std::map;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;

// Preprocess the Burrows-Wheeler Transform bwt of some text
// and compute as a result:
//   * starts - for each character C in bwt, starts[C] is the first position 
//       of this character in the sorted array of 
//       all characters of the text.
//   * occ_count_before - for each character C in bwt and each position P in bwt,
//       occ_count_before[C][P] is the number of occurrences of character C in bwt
//       from position 0 to position P inclusive in the last column.
void PreprocessBWT(const string& bwt, 
                   map<char, int>& starts, 
                   map<char, vector<int> >& occ_count_before)
{
  // Implement this function yourself
    //First fill the starts vector
    vector< pair<char, int> > char_list;
    for (int i = 0; i < bwt.length(); i++)
    {
        char_list.push_back(make_pair(bwt[i],i));
    }
    auto copy_of_list = char_list;
    sort(copy_of_list.begin(), copy_of_list.end());
    bool first$ = true, firstA = true, firstC = true, firstG = true, firstT = true;

    for (int i = 0; i < copy_of_list.size();i++)
    {
        char symbol = copy_of_list[i].first;
        if (first$ && symbol == '$')
        {
            starts.insert(make_pair('$', copy_of_list[i].second));
            first$ = false;
        }
        
        else if (firstA && symbol == 'A')
        {
            starts.insert(make_pair('A', copy_of_list[i].second));
            firstA = false;
        }
        else if (firstC && symbol == 'C')
        {
            starts.insert(make_pair('C', copy_of_list[i].second));
            firstC = false;
        }
        else if (firstG && symbol == 'G')
        {
            starts.insert(make_pair('G', copy_of_list[i].second));
            firstG = false;
        }
        else if (firstT && symbol == 'T')
        {
            starts.insert(make_pair('T', copy_of_list[i].second));
            firstT = false;
            break;
        }
        else
            continue;
    }
    int n = bwt.length();
    vector<int> count$(n,0), countA(n,0), countC(n,0), countG(n,0), countT(n,0);
    int total$ = 0, totalA = 0, totalC = 0, totalG = 0, totalT = 0;
    for (int i = 0; i < char_list.size();i++)
    {
        char c = char_list[i].first;
        switch (c)
        {
            case '$': total$+=1; break;
            case 'A': totalA+=1; break;
            case 'C': totalC+=1; break;
            case 'G': totalG+=1; break;
            case 'T': totalT+=1; break;
            default: break;
        }
        count$[i] = total$; countA[i] = totalA; countC[i] = totalC; countG[i] = totalG; countT[i] = totalT;
    }
    occ_count_before.insert(make_pair('$',count$));
    occ_count_before.insert(make_pair('A',countA));
    occ_count_before.insert(make_pair('C',countC));
    occ_count_before.insert(make_pair('G',countG));
    occ_count_before.insert(make_pair('T',countT));
}

// Compute the number of occurrences of string pattern in the text
// given only Burrows-Wheeler Transform bwt of the text and additional
// information we get from the preprocessing stage - starts and occ_counts_before.
int CountOccurrences(const string& pattern, 
                     const string& bwt,
                     map<char, int>& starts,
                    map<char, vector<int> >& occ_count_before) {
  // Implement this function yourself
    vector <char> pattern_list(pattern.length(), 'z');
    for (int i = 0; i < pattern.length(); i++)
    {
        pattern_list[i] = pattern[i];
    }
    //Initialise the top and bottom pointers.
    int top = 0, bottom = bwt.length()-1;
    while (top <= bottom)
    {
        if (!pattern_list.empty())
        {
            char symbol = pattern_list.back();
            cout << "symbol = " << symbol << endl;
            pattern_list.pop_back(); // Remove last letter from pattern
            //Now check if positions from top to bottom in the last column contain at least 1 occurence of symbol:
            int count = occ_count_before[symbol][bottom];
            if (count > 0)
            {
                top = starts[symbol] + occ_count_before[symbol][top]-1;
                bottom = starts[symbol] + occ_count_before[symbol][bottom]-1;
            }
            else
                return 0;
        }
        else
            return (bottom - top + 1);
    }
  return -100; // now my code isn't even entering the while loop lol
}
     

int main() {
  string bwt;
  cin >> bwt;
  int pattern_count;
  cin >> pattern_count;
  // Start of each character in the sorted list of characters of bwt,
  // see the description in the comment about function PreprocessBWT
  map<char, int> starts;
  // Occurrence counts for each character and each position in bwt,
  // see the description in the comment about function PreprocessBWT
  map<char, vector<int> > occ_count_before;
  // Preprocess the BWT once to get starts and occ_count_before.
  // For each pattern, we will then use these precomputed values and
  // spend only O(|pattern|) to find all occurrences of the pattern
  // in the text instead of O(|pattern| + |text|).
  PreprocessBWT(bwt, starts, occ_count_before);
    /*
    //To debug
    cout << "For debugging -------" << endl;
    cout << "Starts: \n";
    for(auto elem : starts)
    {
        std::cout << elem.first << "--->" << elem.second<< endl;
    }
    cout << endl;
    cout << "occ_count_before:  \n";
    for(auto elem : occ_count_before)
    {
        std::cout << elem.first << "--->";
        for(auto v : elem.second)
        {
            cout << v << " ";
        }
        cout <<endl;
    }
    cout << "End debug --------------" << endl;
     */
  for (int pi = 0; pi < pattern_count; ++pi) {
    string pattern;
    cin >> pattern;
    int occ_count = CountOccurrences(pattern, bwt, starts, occ_count_before);
    printf("%d ", occ_count);
  }
  printf("\n");
  return 0;
}
