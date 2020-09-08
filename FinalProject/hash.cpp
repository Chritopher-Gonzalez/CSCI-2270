// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"
using namespace std;
//constructor
HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
    {
        table[i] = nullptr;
    }
}
//deconstructor
HashTable::~HashTable()
{
  node* temp;
  node* tempNext;
  for(int i = 0; i < tableSize; i++)
  {
    temp = table[i];
    while(temp)
    {
      tempNext = temp->next;
      delete temp;
      temp = tempNext;
    }
    table[i] = nullptr;
  }
  delete[] table;
  table = nullptr;
}


//Private Funnctions
/*
 * Purpose: Hash function using DJB2 algorithm
 * @param string of word that
 * @return hash of the word
*/
unsigned int HashTable::hashFunction(string word)
{
  unsigned int hash = 5381;
  unsigned int length = word.length();
  for(unsigned int i = 0; i < length; i++)
  {
    hash = hash * 33 + word[i];
  }
  hash = hash % tableSize;
  return hash;
}
/*
 * Purpose: creates new node
 * @param string of word for new node
 * @param pointer to next node in linked list
 * @param interger with the frequency of that word
 * @return pointer to new node
*/
node* HashTable::createNode(string word, node* next, int frequency)
{
  node* temp = new node(word, next, frequency);
  return temp;
}
/*
 * Purpose: helper function to increment the frequency of a word
 * @param string of word
 * @return N/A
*/
void HashTable::incrementCount(string word)
{
  int index = hashFunction(word);
  node * temp = table[index];
  while(word != temp->word)
  {
    temp = temp->next;
  }
  temp->frequency++;
}


//Public Functions:
/*
 * Purpose: search hashTable for a word
 * @param string of word to be searched for
 * @return node of word
*/
node* HashTable::search(string word)
{
  //Compute the index by using the hash function
  int index = hashFunction(word);
  node* entry = table[index];
  //Search the list at that specific index and return the node if found
  while(entry)
  {
    if(entry->word == word)
    {
      return entry;
    }
    entry = entry->next;
  }
  return NULL;
}
/*
 * Purpose: inserts element into hashtable
 * @param string of word to be inserted
 * @return True if new word. false if exsiting word
*/
bool HashTable::insert(string word)
{
  //if its a new word
  if(!search(word))
  {
    // Use the hash function on the word to get the index/slot,
    int index = hashFunction(word);
    // allocate memery for new node
    node* temp = table[index];
    //if linklist is empty
    if(!temp)
    {
      temp = createNode(word, NULL, 1);
      table[index] = temp;
    }
    //Collisions happens
    else
    {
      node* entry = createNode(word, temp, 1);
      table[index] = entry;
      numCollisions++;
    }
    numItems++;
    return true;
  }
  else
  {
    incrementCount(word);
    return false;
  }
}
/*
* Purpose: prints every word in hashtable
* @param N/A
* @return N/A
*/
void HashTable::printTable()
{
  for (int i = 0; i < tableSize; i++)
  {
    cout << i <<"|| ";
    //TODO
    node* temp = table[i];
    while(temp != NULL)
    {
      cout << temp->word << " ";
      temp = temp->next;
    }
    cout << endl;
  }
}
/*
* Purpose: add all frequency in hash table, to get total amount of words
* @param N/A
* @return total amount of words
*/
void HashTable::mostFrequent(int n)
{
  int i,j,k;
  //initalize frequent n words array
  node** frequent = new node* [n];
  for(i = 0; i < n; i++)
  {
    frequent[i] = nullptr;
  }
  //inserting into frequent n words
  for(i = 0; i < tableSize; i++)
  {
    node* temp = table[i];
    while(temp)
    {
      for(j = 0; j < n && frequent[j]; j++)
      {
        if(temp->frequency > frequent[j]->frequency)
        {
          break;
        }
      }
      if(j < n)
      {
        for(k = n-1; k >= j; k--)
        if(k+1 != n)
        frequent[k+1] = frequent[k];
        frequent[j] = temp;
      }
      temp = temp->next;
    }
  }
  for(i = 0; i < n; i++)
  {
    node* temp = frequent[i];
    if(temp)
    {
      cout << i << ". " << temp->frequency << " - " << temp->word << endl;
    }
  }
  delete[] frequent;
}
/*
* Purpose: add all frequency in hash table, to get total amount of words
* @param N/A
* @return total amount of words
*/
int HashTable::getTotalNumWords()
{
  int total = 0;
  for(int i = 0; i < tableSize; i++)
  {
    node* temp = table[i];
    while(temp)
    {
      total += temp->frequency;
      temp = temp->next;
    }
  }
  return total;
}
