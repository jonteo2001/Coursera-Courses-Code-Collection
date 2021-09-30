#include <iostream>
#include <vector>

using std::vector;
using std::pair;

// Create a global vector
vector<bool> visited;
void Explore(vector< vector<int> >&adj, vector<int> vertex, int index)
{
    visited[index] = true;
    for (int i = 0; i < vertex.size(); i++)
    {
        if (!visited[vertex[i]])
        {
            Explore(adj, adj[vertex[i]], vertex[i]);
        }
    }
}
int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
    Explore(adj, adj[x], x); //Explore the component of the tree connected to Node x
    // Mark all nodes in the component as visited.
    // If y is visited, then y is in the same component as x.
    
    // Now check the visited vector.
    return (visited[y] == true);
}

int main() {
  size_t n, m;
    std::cin >> n >> m;
    // New line
    visited.resize(n, false);
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1); // add this to the x adjacency list
    adj[y - 1].push_back(x - 1); // add this to the y adjacency list
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
