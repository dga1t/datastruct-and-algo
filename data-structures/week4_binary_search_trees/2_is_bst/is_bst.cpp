#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>
//The goal of this Program is to check if the Binary Tree entered by the user is Binary Search Tree or not.
//A binary search tree is a node based data structure for storing, extracting, inserting and deleting data.
//To check if a binary tree is a binary search tree it must follow the following rules:
//the left subtree of a node contain nodes with key less that this subtree's parent node, the right subtree of a node contain nodes with key greater that this subtree's parent node
//and both the left and right subtree must follow the same rules.

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTree(const vector<Node>& tree,const int& node,int Min,int Max) {
  if (node == -1)    //if the tree or subtree is empty return true (it means we checked until the leaves of the tree)
  {
    return true;
  }

  //to implement a fast and efficent way to check the validity of the tree we will set a range for each node if it lies inside it then we continue to the next node.
  if (tree[node].key > Min && tree[node].key < Max
    && IsBinarySearchTree(tree, tree[node].left, Min, tree[node].key)
    && IsBinarySearchTree(tree, tree[node].right, tree[node].key, Max))
    //The Min and Max variables are responsible for the range we first check. If the node's key is between the range
    //starting from the first node in the tree we will define the range by the limits.h library.
    //It can be very large or very small as it doesnt's matter for the parent node of the tree. Now there are two more conditions.
    //For the left node or left subtree we will call the function recursively, assigning the minimim to be the limit.h constant
    //and the maximum to the parent node of this subtree.
    //Doing so for the right node of the current node but reversing the mechanism of the max and min.
    //We can go through all the nodes recursively until we are finished succesfuly to return true.
  {
    return true;
  }
  //If one of these Conditions isn't met we return false.
  else 
  {
    return false;
  }
}

bool Check(const vector<Node>& tree) {
  if (tree.size() == 0)   //if there are no nodes structure in vector tree then the tree is empty
  {
    return true;          //and we consider it a BST(Binary Search Tree)
  }
  //else return the result of the main function
  return IsBinarySearchTree(tree, 0, INT_MIN, INT_MAX);
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
  if (Check(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
