#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;
using namespace std;

class TreeOrders {
  int n;
  vector <int> key; // stores the key
  vector <int> left; // stores left child
  vector <int> right; // stores right child
    // A vector to store the parent of the key at index i
    vector <int> parent; // stores parent of the key
    // A boolean vector to store if I have visited the i-th node of the tree
    vector <bool> visited;

public:
  void read() {
    cin >> n;
    key.resize(n);
      visited.resize(n, false);
    left.resize(n);
    right.resize(n);
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
        //Store the parent of i-th key
        if (i != 0)
        {
            if (left[i] != -1)
                parent[left[i]] = i;
            if (right[i] != -1)
                parent[right[i]] = i;
        }
        else
            parent[i] = -1; //first node is the root
    }
  }
    // New methods
    vector<int> InOrderTraversal(vector<int>& order, int index)
    {
        if (left[index] != -1 && !visited[left[index]])
            return InOrderTraversal(order, left[index]);
        if (!visited[index])
            {order.push_back(key[index]); visited[index] = true;}
        if (right[index] != -1 && !visited[right[index]])
            return InOrderTraversal(order, right[index]);
        /*
        If the code reaches this point, that means it is at a couple of places
        1) leaf nodes
        2) it has finished the entire tree and has nowhere to go
        So we entertain these 2 possibilities
        */
        if (order.size() < n) // Tree reached a leaf and needs to return to the parent
            return InOrderTraversal(order, parent[index]);//restart from the root
        else
            return order; // Traversal complete.
    }
    vector<int> PreOrderTraversal(vector<int>& order, int index)
    {
        if (!visited[index])
            {order.push_back(key[index]); visited[index] = true;}
        if (left[index] != -1 && !visited[left[index]])
            return PreOrderTraversal(order, left[index]);
        if (right[index] != -1 && !visited[right[index]])
            return PreOrderTraversal(order, right[index]);
        /*
        If the code reaches this point, that means it is at a couple of places
        1) leaf nodes
        2) it has finished the entire tree and has nowhere to go
        So we entertain these 2 possibilities
        */
        if (order.size() < n) // Tree reached a leaf and needs to return to the parent
            return PreOrderTraversal(order, parent[index]);//restart from the root
        else
            return order; // Traversal complete.
    }
    vector<int> PostOrderTraversal(vector<int>& order, int index)
    {
        if (left[index] != -1 && !visited[left[index]])
            return PostOrderTraversal(order, left[index]);
        if (right[index] != -1 && !visited[right[index]])
            return PostOrderTraversal(order, right[index]);
        if (!visited[index])
            {order.push_back(key[index]); visited[index] = true;}
        /*
        If the code reaches this point, that means it is at a couple of places
        1) leaf nodes
        2) it has finished the entire tree and has nowhere to go
        So we entertain these 2 possibilities
        */
        if (order.size() < n) // Tree reached a leaf and needs to return to the parent
            return PostOrderTraversal(order, parent[index]);//restart from the root
        else
            return order; // Traversal complete.
    }
  vector <int> in_order() {
    fill(visited.begin(), visited.end(), false); // reset all nodes to not visited
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
      result = InOrderTraversal(result, 0);
    return result;
  }

  vector <int> pre_order() {
    fill(visited.begin(), visited.end(), false); // reset all nodes to not visited
    vector<int> result;
      result = PreOrderTraversal(result, 0);
    // Finish the implementation
    // You may need to add a new recursive method to do that
    
    return result;
  }

  vector <int> post_order() {
    fill(visited.begin(), visited.end(), false); // reset all nodes to not visited
    vector<int> result;
      result = PostOrderTraversal(result, 0);
    // Finish the implementation
    // You may need to add a new recursive method to do that
    
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

