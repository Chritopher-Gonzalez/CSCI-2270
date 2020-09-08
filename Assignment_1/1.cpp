#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
  for(int i = 0; i <= numEntries; i++)
  {
    if(myArray[i] == -1)
    {
      myArray[i] = newValue;
    }
  }

  for(int i = numEntries; i > 0 ; i--)
  {
    if(myArray[i] < myArray[i-1] && myArray[i-1] != -1)
    {
      int temp = myArray[i];
      myArray[i] = myArray[i-1];
      myArray[i-1]= temp;
    }
  }

  return numEntries+1;
}

int main(int argc, char** argv)
{
  int sorted[100]={0};
  for(int i = 0; i < 100; i++)
  {
    sorted[i] = -1;
  }
  string line;
  int i = 0;
  ifstream myfile;
  myfile.open(argv[1]);

  if(myfile.is_open())
  {
    while(getline(myfile, line))
    {
      insertIntoSortedArray(sorted, i, stoi(line));

      for (int j = 0; j < 100; j++)
      {
        if(j == 0)
        {
          cout << sorted[j];
        }
        else if(sorted[j] != -1)
        {
          cout << "," << sorted[j];
        }
      }
      cout << endl;

      i++;
    }
      myfile.close();
  }
  else
  {
    cout << "Failed to open the file." << endl;
  }
}
