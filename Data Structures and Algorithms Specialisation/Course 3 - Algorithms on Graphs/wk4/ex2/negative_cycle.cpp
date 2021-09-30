#include <iostream>
#include <vector>
#include <limits>
using std::vector;
//Some global variables
vector<long> dist;
const long INF = std::numeric_limits<int>::max();
//Edge relaxation function
int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
    //Create a graph with a fake vertex of cost 0, that joins every node in the graph
    dist[0] = 0;
    for (int i = 0; i < adj.size(); i++)
    {
        for(int u = 0; u < adj.size(); u++)
        {
            for (int k = 0; k < adj[u].size(); k++)
            {
                int v = adj[u][k];
                //Edge relaxation step
                if(dist[u] != INF && dist[v] > dist[u] + static_cast<long>(cost[u][k]))
                {
                    dist[v] = dist[u] + static_cast<long>(cost[u][k]);
                    if(i == adj.size() - 1) return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
    dist.resize(n+1, INF);
  vector<vector<int> > adj(n+1, vector<int>());
  vector<vector<int> > cost(n+1, vector<int>());
    for (int i = 0; i < adj.size(); i++)
    {
        adj[0].push_back(i);
        cost[0].push_back(0);
    }
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x].push_back(y);
    cost[x].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
