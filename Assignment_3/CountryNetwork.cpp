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

  if (head == NULL)
  {
    head = temp;
    cout << "adding: " << countryName << " (HEAD)" << endl;
  }
  else if(previous == NULL)
  {
    temp->next = head;
    head = temp;
    cout << "adding: " << countryName << " (HEAD)" << endl;
  }
  else if (previous->next != NULL)
  {
    Country* temp1 = previous->next;
    temp->next = temp1;
    previous->next = temp;
    cout << "adding: " << countryName << " (prev: " << previous->name <<")" << endl;
  }
  else
  {
    previous->next = temp;
    cout << "adding: " << countryName << " (prev: " << previous->name <<")" << endl;
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
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
  Country* temp;
  temp = head;

  while (temp != NULL)
  {
    temp->message = message;
    temp->numberMessages++;
    cout << temp->name << " [# messages received: " << temp->numberMessages << "] received: " << temp->message << endl;
    if(temp->name == receiver)
    {
      break;
    }
    temp = temp->next;
  }
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
