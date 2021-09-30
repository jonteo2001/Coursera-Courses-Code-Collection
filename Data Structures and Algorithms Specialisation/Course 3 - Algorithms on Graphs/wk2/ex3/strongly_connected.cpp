#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

// Creating global variable
vector <bool> visited;
vector <int> postvisit;
vector <bool> ingraph; // Due to the lack of a better name, this is to remove the vertex
// from the graph once it has been marked as an SCC.
vector <int> scc_stack; // To record an scc stack
void ExploreWithPost(vector<vector <int> >&adjR, vector<int>& neighbours, int index)
{
    visited[index] = true;
    for (int i = 0; i < neighbours.size(); i++)
    {
        if (!visited[neighbours[i]])
            ExploreWithPost(adjR, adjR[neighbours[i]], neighbours[i]);
    }
    postvisit.insert(postvisit.begin(), index); // largest post order number will be at the beginning of the graph G^R. This is the source vertex.
}
void Explore(vector<vector<int> >&adj, vector<int> neighbours, int index)
{
    visited[index] = true; // set the visited to true
    //ingraph[index] = false; // remove vertex from graph
    for (int i = 0; i < neighbours.size(); i++)
    {
        if (!visited[neighbours[i]] && ingraph[neighbours[i]])
            Explore(adj, adj[neighbours[i]], neighbours[i]);
    }
    scc_stack.push_back(index); // add this index to the stack
}
void DepthFirstSearch(vector<vector<int> > &adjR)
{
    visited.assign(visited.size(), false); // reset all to false
    for (int i = 0; i < adjR.size(); i++)
    {
        if (!visited[i])
        {
            ExploreWithPost(adjR, adjR[i], i);
        }
    }
}
int DepthFirstSearchSCC(vector<vector<int> > &adj)
{
    int num_sccs = 0;
    visited.assign(visited.size(), false); // reset all to false
    for (int i = 0; i < postvisit.size(); i++)
    {
        if (!visited[postvisit[i]] && ingraph[postvisit[i]]) // if node has not been visited, yet and node is ingraph
        {
            Explore(adj, adj[postvisit[i]], postvisit[i]);
            num_sccs+=1; // each time the Explore command
            // Now remove all vertices in the stack from the graph
            for (int i = 0; i < scc_stack.size(); i++)
            {
                ingraph[scc_stack[i]] = false;
            }
            //Clear the stack
            scc_stack.clear();
        }
    }
    return num_sccs;
}
int number_of_strongly_connected_components(vector<vector<int> > &adj, vector<vector<int> > &adjR) {
    DepthFirstSearch(adjR); // This routine will ultimately fill the postvisit vector.
    //Using the postvisit vector, now find the number of SCCs
    int result = DepthFirstSearchSCC(adj); // Calculates the number of SCCs on actual graph
  //write your code here
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
    visited.resize(n, false);//Added code
    ingraph.resize(n, true); // Set all nodes to be in the graph
    vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > adjR(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1); //Actual Graph
      //Create the reverse graph
      adjR[y-1].push_back(x-1); // Creates an edge from Y back to X, but no edge from X to Y.
  }
  std::cout << number_of_strongly_connected_components(adj, adjR);
}
