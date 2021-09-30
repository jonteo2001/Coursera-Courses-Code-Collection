#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

// Create a global queue.
queue <int> bfsQueue;
// Create a global vector for distance
vector<int> dist;
// Create a global infinity variable
int INF = -1; // initialised to -1 but will be adjusted upon resize.

int distance(vector<vector<int> > &adj, int s, int t) { // to write the BFS algorithm
    //write your code here
    dist[s] = 0; // set source node to be 0
    bfsQueue.push(s);// enqueue node
    while (!bfsQueue.empty())
    {
        int u = bfsQueue.front(); bfsQueue.pop();
        vector<int> neighbours = adj[u];
        for (int i = 0; i < neighbours.size(); i++)
        {
            if (dist[neighbours[i]] == INF)
            {
                bfsQueue.push(neighbours[i]);
                dist[neighbours[i]] = dist[u] + 1;
            }
        }
    }
    //After running the BFS algorithm,
    //return the shortest path to the destination node.
    return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
    dist.resize(n, INF);
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t; // Last line of input
  s--, t--; //decrement the node index by 1
  std::cout << distance(adj, s, t);
}
