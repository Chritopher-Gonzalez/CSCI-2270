/****************************************************************/
/*                   Assignment 4 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    string input;
    bool list = false;
    CountryNetwork CountryNet;

    while(input != "8")
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
        case 4:
        {
          string country;
          cout << "Enter a country name:" << endl;
          getline(cin, country);
          CountryNet.deleteCountry(country);
          cout << "== CURRENT PATH ==" << endl;
          CountryNet.printPath();
          cout << "===" << endl;
          break;
        }
        case 5:
        {
          CountryNet.reverseEntireNetwork();
          cout << "== CURRENT PATH ==" << endl;
          CountryNet.printPath();
          cout << "===" << endl;
          break;
        }
        case 6:
        {
          string rotated;
          cout << "Enter the count of values to be rotated:" << endl;
          getline(cin, rotated);
          CountryNet.rotateNetwork(stoi(rotated));
          cout << "== CURRENT PATH ==" << endl;
          CountryNet.printPath();
          cout << "===" << endl;
          break;
        }
        case 7:
        {
          cout << "Network before deletion"<< endl;
          cout << "== CURRENT PATH ==" << endl;
          CountryNet.printPath();
          cout << "===" << endl;
          CountryNet.deleteEntireNetwork();
          cout << "Network after deletion"<< endl;
          cout << "== CURRENT PATH ==" << endl;
          CountryNet.printPath();
          cout << "===" << endl;
          break;
        }
      }
    }
    cout << "Quitting... cleaning up path:" << endl;
    cout << "== CURRENT PATH ==" << endl;
    CountryNet.printPath();
    cout << "===" << endl;
    if(!CountryNet.isEmpty())
    {
      CountryNet.deleteEntireNetwork();
    }
    if(CountryNet.isEmpty())
    {
      cout << "Path cleaned" << endl;
      cout << "Goodbye!" << endl;
      return 0;
    }
    cout << "Error: Path NOT cleaned" << endl;
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
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network" << endl;
    cout << " 6. Rotate Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
