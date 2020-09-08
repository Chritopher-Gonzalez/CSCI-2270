/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
    head = NULL;
}
/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
  if(head == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
 void CountryNetwork::insertCountry(Country* previous, string countryName)
 {
  Country* temp = new Country;
  temp->name = countryName;
  temp->next = NULL;

  // adds node to empty list
  if (head == NULL)
  {
    head = temp;
    cout << "adding: " << countryName << " (HEAD)" << endl;
  }
  // adds node to front of list
  else if(previous == NULL)
  {
    temp->next = head;
    head = temp;
    cout << "adding: " << countryName << " (HEAD)" << endl;
  }
  //adds node to middle of list
  else if (previous->next != NULL)
  {
    Country* temp1 = previous->next;
    temp->next = temp1;
    previous->next = temp;
    cout << "adding: " << countryName << " (prev: " << previous->name <<")" << endl;
  }
  //adds node to end of list
  else
  {
    previous->next = temp;
    cout << "adding: " << countryName << " (prev: " << previous->name <<")" << endl;
  }
 }

/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName)
{
  Country *pres = head;
	Country *prev = NULL;
  bool countryFound = false;

  if(pres->name == countryName)
  {
    head = head->next;
    delete pres;
    return;
  }

  while(pres != NULL)
  {
    if(pres->name == countryName)
    {
      countryFound = true;
      break;
    }
    else
    {
      prev = pres;
      pres = pres->next;
    }
  }

  if(countryFound)
  {
    prev ->next = pres->next;
    delete pres;
  }
  else
  {
    cout << "Country does not exist." << endl;
  }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
 void CountryNetwork::loadDefaultSetup()
 {
   insertCountry(head,"United States");
   insertCountry(head,"Canada");
   insertCountry(head -> next,"Brazil");
   insertCountry(head-> next-> next,"India");
   insertCountry(head-> next-> next-> next,"China");
   insertCountry(head-> next-> next-> next-> next,"Australia");
 }


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
 Country* CountryNetwork::searchNetwork(string countryName)
 {
   Country* temp;
   temp = head;

   while(temp != NULL)
   {
     if(temp->name == countryName)
     {
       return temp;
     }
     else
     {
       temp = temp->next;
     }
   }
   return NULL;
 }


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
  //Nodes pointing to current and next nodes
  Country *pres = head;
	Country *next = NULL;

  while(pres != NULL)
  {
    //saves next node
    next = pres->next;
    //deletes current node
    cout << "deleting: " << pres->name << endl;
    delete pres;
    //curent is now the next in list
    pres = next;
  }

  // points head to NULL
  head = NULL;
  cout << "Deleted network" << endl;
}

/*
 * Purpose: Rotate the linked list i.e. move 'n' elements from
 * the back of the the linked to the front in the same order.
 * @param number elements to be moved from the end of the list to the beginning
 * @return none
 */
void CountryNetwork :: rotateNetwork(int n)
{
  //declares temp pointers
  int i = 0;
  Country *last = head;
  Country *pres;
  Country *prev;

  // check if list is empty
  if(head == NULL)
  {
    cout << "Linked List is Empty" << endl;
    return;
  }

  while(last->next != NULL)
  {
    if(i < n)
    {
      prev = pres;
      pres = last;
    }
    last = last->next;
    i++;
  }

  // checks if n is bigger than list or less than 1
  if(n > i || n < 1)
  {
    cout << "Rotate not possible" << endl;
    return;
  }

  last->next = head;
  head = prev->next->next;
  prev->next->next = NULL;
  cout << "Rotate Complete" << endl;

}

/*
 * Purpose: reverse the entire network
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork()
{
  //defines pointers present, previous and next
  Country *pres = head;
  Country *prev = NULL;
  Country *next = NULL;

  while(pres != NULL)
  {
    //stores next node
    next = pres->next;

    //reverses the pointer to next node
    pres->next = prev;

    //move to next node
    prev = pres;
    pres = next;
  }

  //point the head
  head = prev;
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
  Country* temp;
  temp = head;

  if(temp == NULL)
  {
    cout << "nothing in path" << endl;
  }
  else
  {
    while(temp != NULL)
    {
      cout << temp->name <<" -> ";

      temp = temp->next;
    }
    cout << "NULL"  << endl;
  }

}
