#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using namespace std;
struct Node {
  int key;
    int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long long key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};
vector<Node> tree; // Global tree

void inorder_traversal(vector<int> &result, int root) {
    if (root == -1) return;
    inorder_traversal(result, tree[root].left);
    result.push_back(root); // NO LONGER THE VALUE - BUT THE INDEX!
    inorder_traversal(result, tree[root].right);
}

vector <int> in_order(const vector<Node>& tree) {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    inorder_traversal(result, 0);

    return result;
}
bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
    vector <int> result = in_order(tree);
    if (tree.size() > 1)
    {
        for (int i = 0; i < result.size()-1; i++)
        {
            if (tree[result[i+1]].key < tree[result[i]].key) return false;
            if ((tree[result[i]].key == tree[result[i+1]].key)/* if 2 consecutive elements are equal*/ &&
                (tree[result[i+1]].left == result[i] /* if the i+1 element is the left child of i */)) return false;
        }
    }
    return true;
}

int main() {
  int nodes;
  cin >> nodes;
    if (nodes == 0) // added for test case 3 for ex2
    {cout << "CORRECT" << endl; return 0;} // added for test case 3 for ex2
  for (int i = 0; i < nodes; ++i) {
      long long key;
      int left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)){
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
