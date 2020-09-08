/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/
#include "CountryNetwork.cpp"
#include "CountryNetwork.hpp"
// you may include more libraries as needed

// declarations for main helper-functions
void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
  string input;
  bool list = false;
  CountryNetwork CountryNet;

  while(input != "5")
  {
    displayMenu();
    getline(cin, input);

    int menuChoice = stoi(input);
    switch (menuChoice)
    {
      case 1:
      {
        CountryNet.loadDefaultSetup();
        cout << "== CURRENT PATH ==" << endl;
        CountryNet.printPath();
        cout << "===" << endl;
        list = true;
        break;
      }
      case 2:
      {
        cout << "== CURRENT PATH ==" << endl;
        CountryNet.printPath();
        cout << "===" << endl;
        break;
      }
      case 3:
      {
        string receiver;
        string message;
        cout << "Enter name of the country to receive the message:" << endl;
        getline(cin, receiver);
        cout << "Enter the message to send:" << endl << endl;
        getline(cin,message);
        if(CountryNet.searchNetwork(receiver) != NULL)
        {
          CountryNet.transmitMsg(receiver, message);
        }
        else if(list != true)
        {
          cout << "Empty list" << endl;
        }
        else
        {
          cout << "Country not found" << endl;
        }
        break;
      }
      case 4:
      {
        bool vaildCountry = false;
        string newCountry;
        string prev;
        cout << "Enter a new country name:" << endl;
        getline(cin, newCountry);
        cout << "Enter the previous country name (or First):" << endl;

        while(vaildCountry != true)
        {
          getline(cin, prev);
          if(prev == "First")
          {
            CountryNet.insertCountry(NULL, newCountry);
            vaildCountry = true;
            break;
          }
          else if(CountryNet.searchNetwork(prev) != NULL)
          {
            CountryNet.insertCountry(CountryNet.searchNetwork(prev), newCountry);
            vaildCountry = true;
            break;
          }
          cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
        }
        cout << "== CURRENT PATH ==" << endl;
        CountryNet.printPath();
        cout << "===" << endl;
        list = false;
        break;
      }
    }
  }
  cout << "Quitting..." << endl;
  cout << "Goodbye!" << endl;
  return 0;
}

/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
