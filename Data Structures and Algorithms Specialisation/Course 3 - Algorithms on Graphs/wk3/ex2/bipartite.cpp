#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
//Global variables
queue <int> bfsQueue;
vector<int> color;
int UNDEF = 0;// null flag

int bipartite(vector<vector<int> > &adj) {
    //write your code here
    // Take the 1st node as the starting node.
    for (int i = 0; i < color.size(); i++) // Bipartite graph can be disconnected
    {
        if (color[i] == UNDEF)
        {
            color[i] = 1;
            bfsQueue.push(i);
            while (!bfsQueue.empty())
            {
                int u = bfsQueue.front(); bfsQueue.pop();
                vector<int> neighbours = adj[u];
                for (int i = 0; i < neighbours.size(); i++)
                {
                    if (color[neighbours[i]] == UNDEF) // new undiscovered node
                    {
                        bfsQueue.push(neighbours[i]);
                        color[neighbours[i]] = -1*color[u]; //OMG seriously how did i not realise this
                    }
                    else
                    {
                        if (color[neighbours[i]] == color[u])
                        {
                            return 0;
                        }
                    }
                }
            }
        }
    }
    // If the code reaches this point, the graph is bipartite.
    return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
    color.resize(n, UNDEF);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
