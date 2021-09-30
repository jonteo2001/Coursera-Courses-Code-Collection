#include <iostream>
#include <vector>
using std::vector;
using std::pair;
// global vector for visited nodes
vector <bool> visited;
// global vector for recursion stack
vector<bool> recurStack; // True if on stack, False if not on stack
// Global boolean found, initialise to false.
bool found = false; // Denotes whether we have found a cycle or not.

void Explore(vector<vector<int> > &adj, vector<int> &vertex, int index)
{
    visited[index] = true; // mark as visited - previsit
    recurStack[index] = true; // add to stack - previsit
    for (int i = 0; i < vertex.size(); i++)
    {
        if (recurStack[vertex[i]]) {found = true;} // If this node is already on the recursion stack
        if (!visited[vertex[i]] && !found)
        {
            Explore(adj, adj[vertex[i]], vertex[i]); // Explore all neighbouring nodes
        }
    }
    recurStack[index] = false; // Pop from stack (post-visit)
}
int acyclic(vector<vector<int> > &adj) { // wrapper function
  //write your code here
    // implement depth first search
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i] && !found)
            Explore(adj, adj[i], i);
    }
  return (found == true)? 1 : 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
    visited.resize(n, false); // added code
    recurStack.resize(n, false); // added code
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1); //directed edge from x -> y
  }
  std::cout << acyclic(adj);
}
