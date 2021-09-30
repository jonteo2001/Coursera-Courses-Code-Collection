#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
using namespace std;
class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children; //every node has a vector that contains the children
                                // of the node. Note these refer to DIRECT DESCENDANTS

    Node() { //Constructor
      this->parent = NULL; //set parent of node to null - assume root node.
    }

    void setParent(Node *theParent) { //then set a parent via this method.
      parent = theParent;
      parent->children.push_back(this);
    }
};
//Write a function to find the root
Node find_root(vector<Node> nodes)
{
    for (Node n: nodes)
    {
        if (n.parent == NULL)
        {
            return n;
        }
    }
    //For debug incase something screws up
    Node nullexcept = Node();
    nullexcept.key = -1000; // flag to tell me something messed up
    return nullexcept;
}
int Height(Node node)
{
    int max_height = 0;
    // For leaf nodes
    if (node.children.empty())
        return 1;
    //Find root in the vector of nodes
    for (size_t i = 0; i < node.children.size(); i++)
    {
        int heightOfChildSubtree = Height(*(node.children[i]));
        max_height = max(max_height, heightOfChildSubtree);
    }
    max_height +=1;
    return max_height;
}

int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++)
    {
        int parent_index;
        std::cin >> parent_index;
        if (parent_index >= 0)
            nodes[child_index].setParent(&nodes[parent_index]);
        nodes[child_index].key = child_index;
    }

    // Replace this code with a faster implementation
    // First find the root of the tree
    Node root = find_root(nodes);
    if (root.key == -1000) // Error support
        {cout << -1000 << endl; return 0;}
    if (root.children.empty()) // Case where it is a single tree
    {
        cout << 1 << endl; return 0;
    }
    int maxHeight = Height(root);
    
    /*
    for (int leaf_index = 0; leaf_index < n; leaf_index++)
    {
        int height = 0;
        for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
        {
            height++;
            cout << "leaf_index = " << leaf_index << "  *v = " << v->key << "  height = "
            << height<< endl;
        }
        maxHeight = std::max(maxHeight, height);
        cout << "leaf_index = " << leaf_index <<" | MaxHeight = " << maxHeight << endl;
    }
    */
  std::cout << maxHeight << std::endl;
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
