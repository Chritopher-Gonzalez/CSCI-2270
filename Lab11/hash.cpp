// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
  //Compute the index by using the hash function
  int index = hashFunction(key);
  node* entry = table[index];
  //TODO: Search the list at that specific index and return the node if found
  while(entry != NULL)
  {
    if(entry->key == key)
    {
      return entry;
    }
    entry = entry->next;
  }
  return NULL;
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
  if(!searchItem(key))
  {
    // TODO :
    // Use the hash function on the key to get the index/slot,
    int index = hashFunction(key);
    // create a new node with the key and insert it in this slot's list
    node* temp = table[index];
    if(!temp)
    {
      temp = createNode(key, NULL);
      table[index] = temp;
    }
    else
    {
      node* entry = createNode(key, temp);
      table[index] = entry;
    }
    return true;
   }
  else
  {
    cout << "duplicate entry: " << key << endl;
    return false;
  }

}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
  for (int i = 0; i < tableSize; i++)
  {
    cout << i <<"|| ";
    //TODO
    node* temp = table[i];
    while(temp != NULL)
    {
      cout << temp->key << " ";
      temp = temp->next;
    }
    cout <<"  ";
  }
 }
