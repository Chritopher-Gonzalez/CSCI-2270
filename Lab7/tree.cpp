#include <iostream>
#include "tree.hpp"
using namespace std;
#define COUNT 10


/*
Constructor for a Tree object
*/
Tree::Tree()
{
  this->root = NULL;
}

/*
Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void printTreeHelper(Node* currNode){
     if(currNode)
     {
        printTreeHelper( currNode->left);
        cout << " "<< currNode->key;
        printTreeHelper( currNode->right);
     }
 }
void Tree::print2DUtil(Node *root)
{
  printTreeHelper(root);
  cout<<endl;
}

void Tree::preOrderTraverse(Node *node)
{
  if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left sutree */
    preOrderTraverse(node->left);

    /* now recur on right subtree */
    preOrderTraverse(node->right);
}


/*
***************************************************************************
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                        Implement this function
            This function deletes all the nodes in the tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
***************************************************************************
*/
void Tree::deleteTree(Node *node)
{
    if (node == NULL) return;

    /*TODO first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);
    /* TODO then delete the node */
    cout<<"\n Deleting node:"<< node->data;
    delete node;
}

/*
***************************************************************************
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                        Implement this function
          This function gives the sum of all the nodes in the tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
***************************************************************************
*/
int Tree::sumNodes(Node *node)
{
  int sum = 0;
  //TODO Base case
  if (node == NULL)
  {
    return 0;
  }
  //TODO Implement Sum of all nodes
  sum = node->data + sumNodes(node->left) + sumNodes(node->right);

  return sum;
}

/*
 Creates a tree of 7 elements
 */
void Tree::createTree()
{
  Node *root         = new Node(1);
  root->left         = new Node(2);
  root->right        = new Node(3);
  root->left->left   = new Node(4);
  root->left->right  = new Node(5);
  root->right->left  = new Node(6);
  root->right->right = new Node(7);
  this->root = root;
}
