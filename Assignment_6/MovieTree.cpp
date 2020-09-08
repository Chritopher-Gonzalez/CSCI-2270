#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

/*
 * Purpose: helps addMovieNode function recursivly travel the tree then add leaf
 * @param current tree and leaf to be inserted
 * @return new binarry tree with new leaf
 */
MovieNode* insertMovie(MovieNode* current, MovieNode* insert)
{
	// Insert at the head
	if(current == NULL)
	{
		current = insert;
	}
	// insert to the RIGHT
	else if (current->title[0] < insert->title[0])
	{
		current->right = insertMovie(current->right, insert);
	}
	// insert to the LEFT
	else
	{
		current->left = insertMovie(current->left, insert);

	}
	// return new tree
	return current;
}
/*
 * Purpose: helps printMovieInventory function recursivly travel the tree
 * @param current node that it wants to print
 * @return none
 */
void printTree(MovieNode* current)
{
	if (current)
	{
		// print Left subtree
		printTree(current->left);
		// print middle node (parent/current)
		cout << "Movie: " << current->title << " " << current->rating << endl;
		// print Right subtree
		printTree(current->right);
	}
}
/*
 * Purpose: helps findMovie function recursivly travel checking each leaf
 * @param current tree and title to be found
 * @return MoiveNode with matching title
 */
MovieNode* search(MovieNode* current, string title)
{
	if (current)
	{
		//look at current node
		if (current->title == title)
		{
			return current;
		}
		// look at right subtree
		else if (current->title < title)
		{
			return search(current->right, title);
		}
		// look at left subtree
		else if (current->title > title)
		{
			return search(current->left, title);
		}
	}
	return NULL;
}
/*
 * Purpose: helps queryMovies function recursivly travel, print the Nodes that meet the requirments
 * @param current tree, rating and year
 * @return none
 */
void query(MovieNode* current, float rating, int year)
{
	if (current)
	{
		//prints current node
		if(current-> rating >= rating && current->year > year)
		{
			cout << current->title << "(" << current->year << ") " << current->rating << endl;
		}
		//searches left subtree
		query(current->left, rating, year);

		//searches right subtree
		query(current->right, rating, year);
	}
}
/*
 * Purpose: helps averageRating function sum all the ratings
 * @param current tree
 * @return sum of ratings of that subtree
 */
float sumRating(MovieNode* current)
{
  float sum = 0;
	//
  if (current == NULL)
  {
    return 0;
  }

	sum = current->rating + sumRating(current->left) + sumRating(current->right);

  return sum;
}
/*
 * Purpose: helps averageRating function counting all movies stored
 * @param current tree
 * @return num of movies in tree
 */
int numMovies(MovieNode* current)
{
	int num = 1;

  if (!current)
  {
    return 0;
  }
	if(current->left)
	{
		num += numMovies(current->left);
	}
	if(current->right)
	{
		num += numMovies(current->right);
	}

  return num;
}

//constructor
MovieTree::MovieTree()
{
  root = NULL;
}
//deconstructor
MovieTree::~MovieTree()
{

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
	else
	{
		cout << "Tree is Empty. Cannot print" << endl;
	}
}
/*
 * Purpose: add movie to tree
 * @param data of the new movie
 * @return none
 */
void MovieTree::addMovieNode(int ranking, string title, int year, float rating)
{
	//create new node with data
	MovieNode* temp = new MovieNode(ranking, title, year, rating);
	//build new tree with helper function (line 9)
	root = insertMovie(root, temp);
}
/*
 * Purpose: finds movie
 * @param title of movie to be found
 * @return none
 */
void MovieTree::findMovie(string title)
{
	MovieNode* node = search(root, title);
		if (node) // ret is not NULL
		{
			cout << "Movie Info:" << endl;
			cout << "==================" << endl;
			cout << "Ranking:" << node->ranking << endl;
			cout << "Title :" << node->title << endl;
			cout << "Year :" << node->year << endl;
			cout << "rating :" << node->rating << endl;
		}
		else
		{
			cout << "Movie not found." << endl;
		}
}
/*
 * Purpose:Print all the movies with a rating at least as good as rating that are newer than year in the preorder fashion
 * @param rating and year
 * @return none
 */
void MovieTree::queryMovies(float rating, int year)
{
	if(root)
	{
		cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
		query(root, rating, year);
	}
	else
	{
		cout << "Tree is Empty. Cannot query Movies" << endl;
	}
}
/*
 * Purpose:Print the average rating for all movies in the tree.
 * @param none
 * @return none
 */
void MovieTree::averageRating()
{
	if(root)
	{
		float average = sumRating(root) / numMovies(root);
		cout << "Average rating:" << average << endl;
	}
	else
	{
		cout << "Average rating:0.0" << endl;
	}
}
