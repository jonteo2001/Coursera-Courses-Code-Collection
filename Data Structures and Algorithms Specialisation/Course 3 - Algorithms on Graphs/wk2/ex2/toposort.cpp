#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;
//Creating global vector visited
vector<bool> visited;
//Creating global vector for postvisit numbers
vector<int> postvisit;
void Explore(vector <vector<int> > &adj, vector<int>& neighbours, int index)
{
    visited[index]= true;
    for (int i = 0; i < neighbours.size(); i++)
    {
        if (!visited[neighbours[i]])
        {
            Explore(adj, adj[neighbours[i]],neighbours[i]);
        }
    }
    //Upon leaving the vertex_i, insert at the beginning of the postvisit vector.
    postvisit.insert(postvisit.begin(), index);
    // This will create a vector in descending order of post order number.
}

void dfs(vector<vector<int> > &adj) {
  //write your code here
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            Explore(adj, adj[i], i);
        }
    }
} //follow through motion

vector<int> toposort(vector<vector<int> > adj) {
  //vector<int> used(adj.size(), 0);
  //vector<int> order;
  //write your code here
    dfs(adj);
  return postvisit;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
    visited.resize(n, false); // Added code
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
