#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#ifndef BINARYTREE_H
#define BINARYTREE_H

template<typename T>
class TreeNode
{
public:
  T element; // Element contained in the node
  TreeNode<T> * left; // Pointer to the left child
  TreeNode<T> * right; // Pointer to the right child

  TreeNode() // No-arg constructor
  {
    left = nullptr;
    next = nullptr;
  }

  TreeNode(T element) // Constructor
  {
    this->element = element;
    left = nullptr;
    right = nullptr;
  }
};

template<typename T>
class BinaryTree
{
public:
  BinaryTree();
  BinaryTree(T elements[], int arraySize);
  bool insert(T element);
  void inorder();
  void preorder();
  void postorder();
  int getSize();
  bool search(T element);
  void breadthFirstTraversal();
  int depth();
  bool isFullBinaryTree();

private:
  TreeNode<T> * root;
  int size;
  void inorder(TreeNode<T> * root);
  void postorder(TreeNode<T> * root);
  void preorder(TreeNode<T> * root);
  bool search(T element, TreeNode<T> * root);
  int depth(TreeNode<T> * root);
};

template<typename T>
BinaryTree<T>::BinaryTree()
{
  root = nullptr;
  size = 0;
}

template<typename T>
BinaryTree<T>::BinaryTree(T elements[], int arraySize)
{
  root = nullptr;
  size = 0;
  for (int i = 0; i < arraySize; i++)
  {
    insert(elements[i]);
  }
}

/* Insert element into the binary tree * Return true if the element is inserted successfully
* Return false if the element is already in the list */

template<typename T>
bool BinaryTree<T>::insert(T element)
{
  if (root == nullptr)
    root = new TreeNode<T>(element); // Create a new root
  else
  {
    // Locate the parent node
    TreeNode<T> * parent = nullptr;
    TreeNode<T> * current = root;
    while (current != nullptr)
      if (element < current->element)
      {
        parent = current;
        current = current->left;
      }
      else if (element > current->element)
      {
        parent = current;
        current = current->right;
      }
      else
        return false; // Duplicate node not inserted

                      // Create the new node and attach it to the parent node
      if (element < parent->element)
        parent->left = new TreeNode<T>(element);
      else
        parent->right = new TreeNode<T>(element);
  }

  size++;
  return true; // Element inserted
}

/* Inorder traversal */

template<typename T>
void BinaryTree<T>::inorder()
{
  inorder(root);
}

/* Inorder traversal from a subtree */

template<typename T>
void BinaryTree<T>::inorder(TreeNode<T> * root)
{
  if (root == nullptr) return;
  inorder(root->left);
  cout << root->element << " ";
  inorder(root->right);
}

/* Postorder traversal */

template<typename T>
void BinaryTree<T>::postorder()
{
  postorder(root);
}

/** Inorder traversal from a subtree */

template<typename T>
void BinaryTree<T>::postorder(TreeNode<T> * root)
{
  if (root == nullptr) return;
  postorder(root->left);
  postorder(root->right);
  cout << root->element << " ";
}

/* Preorder traversal */

template<typename T>
void BinaryTree<T>::preorder()
{
  preorder(root);
}

/* Preorder traversal from a subtree */

template<typename T>
void BinaryTree<T>::preorder(TreeNode<T> * root)
{
  if (root == nullptr) return;
  cout << root->element << " ";
  preorder(root->left);
  preorder(root->right);
}

/* Get the number of nodes in the tree */

template<typename T>
int BinaryTree<T>::getSize()
{
  return size;
}

template<typename T>
int BinaryTree<T>::depth()
{
  return depth(root);
}

template<typename T>
int BinaryTree<T>::depth(TreeNode<T> * root)
{
  if (root == nullptr) return 0;
  else
    return 1 + max(depth(root->right), depth(root->left));
}

template<typename T>
bool BinaryTree<T>::isFullBinaryTree()
{
  return pow(2.0, depth()) - 1 == size;
}
#endif

int main()
{
  BinaryTree <int> tree1;
  cout << "How many integers in the input? ";
  int size;
  cin >> size;

  cout << "Enter " << size << " integers: ";
  int temp;
  for (int i = 0; i < size; i++)
  {
    cin >> temp;
    tree1.insert(temp);
  }

  cout << "Inorder (sorted): ";
  tree1.inorder();

  cout << "\nPostorder: ";
  tree1.postorder();

  cout << "\nPreorder: ";
  tree1.preorder();

  cout << "\nThe number of nodes is " << tree1.getSize();

  cout << "\ntree1 is full binary tree? " <<
    (tree1.isFullBinaryTree() ? "true" : "false") << endl;

  return 0;
}
