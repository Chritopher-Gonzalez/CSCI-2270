#ifndef HASH_HPP
#define HASH_HPP

#include<iostream>
#include <string>
#include <fstream>
#include<vector>
using namespace std;

//nodes that are stored in the hash table
struct node
{
  string word;
  int frequency;
  struct node* next;
  node(string word, node* next, int frequency)
  {
    this->word = word;
    this->next = next;
    this->frequency = frequency;
  }
  node()
  {
    word = "";
    this->next = NULL;
    this->frequency = 0;
  }
};

class HashTable
{
  private:
    /*instance variables */
    // Pointer to an array containing all nodes
    node **table;
    // No. of nodes (linked lists)
    int tableSize;
    // current size of table
    int numItems = 0;
    //number of Collisions
    int numCollisions = 0;

    /*methods*/
    // hash function to map values to word
    unsigned int hashFunction(string word);
    //creates new node
    node* createNode(string word, node* next, int frequency);
    //increment count of word
    void incrementCount(string word);

  public:
    //cinonstructor
    HashTable(int bsize);
    //Deconstructor
    ~HashTable();
    //searched for word
    node* search(string word);
    // inserts a word into hash table
    bool insert(string word);
    //prints values in table
    void printTable();
    //prints the nth most frequent words used
    void mostFrequent(int n);
    //gets the number of collisions;
    int getCollsions(){return numCollisions;}
    //gets the number of items
    int getNumItems(){return numItems;}
    //sum of the total number of words
    int getTotalNumWords();
};

#endif
