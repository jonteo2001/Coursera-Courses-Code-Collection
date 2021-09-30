#include <iostream>
#include <vector>

using std::vector;
using std::pair;

// Creating global visited vector
vector<bool> visited;

void Explore(vector< vector<int> > &adj, vector<int> vertex, int index)
{
    visited[index] = true;
    for (int i = 0; i < vertex.size(); i++)
    {
        if(!visited[vertex[i]])
        {
            Explore(adj, adj[vertex[i]], vertex[i]);
        }
    }
}
int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  //write your code here
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            Explore(adj, adj[i], i);
            // Each time when it reaches the end of this inner loop,
            // increase counter by 1
            res+=1;
        }
    }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
    visited.resize(n, false); // this line of code is added to main
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
