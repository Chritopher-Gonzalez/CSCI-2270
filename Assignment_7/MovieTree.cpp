#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;
// Add a new node to the list
LLMovieNode* insertLL(LLMovieNode* head, LLMovieNode* insert)
{
  LLMovieNode* pres = head;
  LLMovieNode* prev = NULL;
  // Search for a specified title and return a pointer to that node
  while (pres != NULL && pres->title < insert->title)
  {
    prev = pres;
    pres = pres->next;
  }
  if(prev == NULL)
  {
    insert->next = head;
    head = insert;
  }
  else if(pres == NULL)
  {
    prev->next = insert;
  }
  else
  {
    prev->next = insert;
    insert->next = pres;
  }
  return head;
}
/*
 * Purpose: helps addTreeNode function recursivly travel the tree then add leaf
 * @param current tree and leaf to be inserted
 * @return new binarry tree with new leaf
 */
TreeNode* insertMovie(TreeNode* current, LLMovieNode* insert)
{
	// Insert at the head
	if(current == NULL)
	{
		TreeNode* temp = new TreeNode;
		temp->titleChar = insert->title[0];
		temp->head = insertLL(temp->head, insert);
		current = temp;
	}
	else if(current->titleChar == insert->title[0])
	{
		current->head = insertLL(current->head, insert);
	}
	// insert to the RIGHT
	else if (current->titleChar < insert->title[0])
	{
		current->rightChild = insertMovie(current->rightChild, insert);
	}
	// insert to the LEFT
	else
	{
		current->leftChild = insertMovie(current->leftChild, insert);
	}
	// return new tree
	return current;
}
/*
 * Purpose: helps printMovieInventory function recursivly travel the tree
 * @param current node that it wants to print
 * @return none
 */
void printTree(TreeNode* current)
{
	if (current)
	{
		//tranverse Left subtree
		printTree(current->leftChild);

		// print middle node (parent/current)
		// for every TreeNode (t) in the tree
		cout << "Movies starting with letter: " << current->titleChar << endl;
		// for every LL (m) attached to t

		LLMovieNode* temp = current->head;
		while(temp != NULL)
		{
			cout << " >> " << temp->title << " " << temp->rating << endl;
			temp = temp->next;
		}

		// tranverse Right subtree
		printTree(current->rightChild);
	}
}

//constructor
MovieTree::MovieTree()
{
  root = NULL;
}

void destroyBST(Node *currNode){
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);
         	LLMovieNode* crawler;
         	while(head!=NULL){
         		crawler = head->next;
         		delete head;
         		head = crawler;
         	}
         }
         delete currNode;
         currNode = NULL;
     }
 }
//deconstructor
MovieTree::~MovieTree()
{
  destroyBST(root);
}
/*
 * Purpose: prints movie catlog currently stored
 * @param none
 * @return none
 */
void MovieTree::printMovieInventory()
{
	if(root)
	{
		printTree(root);
	}
}
/*
 * Purpose: add movie to tree
 * @param data of the new movie
 * @return none
 */
void MovieTree::addMovie(int ranking, string title, int year, float rating)
{
  printMovieInventory();
	//create new node with data
	LLMovieNode* temp = new LLMovieNode(ranking, title, year, rating);
	//build new tree with helper function (line 9)
	root = insertMovie(root, temp);
}
TreeNode* getMinValueNode(TreeNode* currNode)
{
  if(currNode->leftChild == NULL)
  {
    return currNode;
  }
  return getMinValueNode(currNode->leftChild);
}
//deletes specified movie from linked list
LLMovieNode* deleteMovieLL(LLMovieNode* head, string title)
{
  LLMovieNode* pres = head;
  LLMovieNode* prev = NULL;
  bool movieFound = false;
  //moive is the head
  if(pres->title == title)
  {
    head = head->next;
    delete pres;
    return head;
  }
  //searches for movie in list
  while(pres != NULL)
  {
    //found the movie
    if(pres->title == title)
    {
      movieFound = true;
      break;
    }
    // tranverse the linked list
    else
    {
      prev = pres;
      pres = pres->next;
    }
  }
  //delete movie
  if(movieFound)
  {
    prev->next = pres->next;
    delete pres;
  }
  else
  {
    cout << "Movie: " << title << " not found, cannot delete." << endl;
  }
  return head;
}
//deletes binary tree node
TreeNode* deleteMovieBST(TreeNode *currNode, string title)
{
  if(currNode == NULL)
  {
    cout << "Movie: " << title << " not found, cannot delete." << endl;
    return NULL;
  }
  else if(title[0] < currNode->titleChar)
  {
    currNode->leftChild = deleteMovieBST(currNode->leftChild, title);
  }
  else if(title[0] > currNode->titleChar)
  {
    currNode->rightChild = deleteMovieBST(currNode->rightChild, title);
  }
  // We found the node with the value
  else
  {
    //delete movie from linked list
    currNode->head = deleteMovieLL(currNode->head, title);
    //delete node if linked list is empty
    if(!currNode->head)
    {
      //Case : No child
      if(currNode->leftChild == NULL && currNode->rightChild == NULL)
      {
        delete currNode;
        return NULL;
      }
      // Only right child
      else if(currNode->leftChild == NULL)
      {
        TreeNode* temp = currNode->rightChild;
        delete currNode;
        return temp;
      }
      //Only left child
      else if(currNode->rightChild == NULL)
      {
        TreeNode* temp = currNode->leftChild;
        delete currNode;
        return temp;
      }
      //Both left and right child
      else
      {
        ///Replace with Minimum from right subtree
        TreeNode* minRight = getMinValueNode(currNode->rightChild);
        currNode->head = minRight->head;
        currNode->titleChar = minRight->titleChar;
        currNode->rightChild = deleteMovieBST(currNode->rightChild, minRight->head->title);
      }
    }
  }
  return currNode;
}
void MovieTree::deleteMovie(string title)
{
  root = deleteMovieBST(root, title);
}
