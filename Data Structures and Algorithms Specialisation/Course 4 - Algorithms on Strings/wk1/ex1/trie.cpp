#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;
/* std::map is a sorted associative container that contains key-value pairs with unique keys
 Keys are sorted by using the comparison function Compare.
 Search, removal, and insertion operations have logarithmic complexity. Maps are usually implemented as red-black trees
 */
typedef map<char, int> edges; // char would be the character of the edge
                                // and int would be the index of the next edge.
typedef vector<edges> trie; // trie is an adjacency list
                            // 1 map for 1 pattern
                            // hence

trie build_trie(vector<string> & patterns) {
  trie t;
  // write your code here
    edges root; //edges that the root is connected to
    t.push_back(root);
    int trie_size = 0;
    for (int it = 0; it < patterns.size(); it++)
    {
        edges temp = t[0]; // intiialise it to the root.
        int currentIndex = 0; // track the current index that currentSymbol is at
        for (int i = 0; i < patterns[it].length(); i++)
        {
            char currentSymbol = patterns[it][i];
            int dest = -1;// to track the destination index
            if (temp.count(currentSymbol)> 0) // Should be either 0 or 1
            {
                dest = temp[currentSymbol]; // index of the next character.
                currentIndex = dest; // go the destination node
                temp = t[currentIndex]; // make the map at the dest node the map
            }
            else
            {
                // Add new index to trie
                trie_size +=1;
                int index = trie_size; // keeps track of number of nodes in trie.
                // each node in trie is defined by an element in trie.
                t[currentIndex][currentSymbol] = index; // add a reference from the parent node to the child
                edges NewEdge; // create the new edge and push back into trie
                // This edge will have the new
                t.push_back(NewEdge);
                // Now that you have added the edge - go down that path
                dest = t[currentIndex][currentSymbol];//find dest
                currentIndex = dest;//update current index
                temp = t[currentIndex]; //update temp
            }
        }
        
    }
    // You just have to build the trie, they will print it out for you!
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
        // i - current node index
        // j.second - end node index
        // j.first - character
    }
  }

  return 0;
}
