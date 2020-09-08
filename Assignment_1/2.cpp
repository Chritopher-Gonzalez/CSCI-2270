#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Park
{
  string parkname;
  string state;
  int area;

  Park()
  {
    parkname = "";
    state = "";
    area = 0;
  }
};

// length: Number of items currently stored in the array
void addPark(Park parks[], string parkname, string state, int area, int length)
{
  Park temp;
  temp.parkname = parkname;
  temp.state = state;
  temp.area = area;
  for(int i = 0; i <= length; i++)
  {
    if(parks[i].area == 0)
    {
      parks[i] = temp;
    }
  }
}

void printList(const Park parks[], int length)
{
  for(int i = 0; i < length; i++)
  {
    cout << parks[i].parkname <<" [" << parks[i].state << "] area: "<< parks[i].area << endl;
  }
}


int main(int argc, char** argv)
{
  string line;
  int i = 0;
  Park parks[56];

  ifstream input;
  input.open(argv[1]);

  ofstream output;
  output.open(argv[2]);

  if(input.is_open())
  {
    while(getline(input, line))
    {
      stringstream ss(line);
      string n;
      string s;
      string a;
      getline(ss, n, ',');
      getline(ss, s, ',');
      getline(ss, a, ',');
      addPark(parks, n, s, stoi(a), i);
      if(parks[i].area > stoi(argv[3])
      {
        output << n << ',' << s << ',' << a << endl;
      }
      i++;
    }
    input.close();
    output.close();
  }

  printList(parks, i);
}
