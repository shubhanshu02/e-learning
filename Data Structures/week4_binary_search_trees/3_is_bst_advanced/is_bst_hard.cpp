#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  long long key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree, int i, long long min, long long max) {
  if (i >= 0) {
    if (tree[i].key < min || tree[i].key >= max) return false;
    if (tree[i].left != -1 && tree[i].key <= tree[tree[i].left].key) return false;
    if (tree[i].right != -1 && tree[i].key > tree[tree[i].right].key) return false;
    return (IsBinarySearchTree(tree, tree[i].left, min, tree[i].key) && IsBinarySearchTree(tree, tree[i].right, tree[i].key, max));
  }
  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (tree.size() == 0) {
    cout << "CORRECT" << endl;
    return 0;
  }
  if (IsBinarySearchTree(tree, 0, INT64_MIN, INT64_MAX)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
