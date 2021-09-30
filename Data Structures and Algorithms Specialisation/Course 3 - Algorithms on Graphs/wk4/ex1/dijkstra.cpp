#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::make_pair;
using std::numeric_limits;
// Declare an alias for my convenience
using NodeCostPair = pair<int, long long>;
//this distance is updated or not.

// Comparison function
// By default priority_queue keeps the value with highest value as the root i.e. it makes
// max-heap and we need a min-heap. So we just make a comparator to reverse the order.
struct cmp
{
    bool operator()(NodeCostPair &a, NodeCostPair &b)
    {
        return a.second > b.second;
    }
};
// Global priority queue
priority_queue< NodeCostPair, vector <NodeCostPair>, cmp > pq;
//Global distance vector
vector <long long> dist;
// Flag for infinity
const long long INF = numeric_limits<int>::max();


// Dijkstra algorithm
long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code here
    dist[s] = 0;// source vertex
    pq.push(make_pair(s, dist[s]));
    while (!pq.empty())
    {
        NodeCostPair u = pq.top(); pq.pop();
        vector <int> neighbours = adj[u.first];
        vector <int> weights = cost[u.first];
        for (int i = 0; i < neighbours.size(); i++)
        {
            //include all outgoing edges into the closed set
            if (dist[neighbours[i]] > dist[u.first] + static_cast<long long>(weights[i])) //Edge relaxation
            {
                dist[neighbours[i]] = dist[u.first] + static_cast<long long>(weights[i]);
                //Add all outgoing edges into the priority queue.
                // So your queue will have useless elements but it's okay!!
                pq.push(make_pair(neighbours[i], dist[neighbours[i]]));//This is a new upper bound!
                
            }
        }
    }
    return (dist[t]==INF)?-1:dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
    dist.resize(n, INF);
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w); // vector to store cost
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
