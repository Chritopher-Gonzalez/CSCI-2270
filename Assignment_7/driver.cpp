#include "MovieTree.cpp"
#include <iostream>
using namespace std;

void displayMenu()
{
  cout << "======Main Menu======" << endl;
  cout << "1. Print the inventory" << endl;
  cout << "2. Delete a movie" << endl;
  cout << "3. Quit" << endl;
}

int main (int argc, char* argv[])
{
  MovieTree movies;
  string line, input;
  ifstream file;
  file.open(argv[1]);

  //load data from csv file
  if(file.is_open())
  {
    while(getline(file, line))
    {
      //parse line
      stringstream ss(line);
      string ranking, title, year, rating;
      getline(ss, ranking, ',');
      getline(ss, title, ',');
      getline(ss, year, ',');
      getline(ss, rating, ',');
      // add new movie
      movies.addMovie(stoi(ranking), title, stoi(year), stof(rating));
    }
    //close file
    file.close();
  }
  while(input != "3")
  {
    displayMenu();
    getline(cin, input);
    int menuChoice = stoi(input);
    switch (menuChoice)
    {
      case 1:
      {
        movies.printMovieInventory();
        break;
      }
      case 2:
      {
        string deleteMovie;
        cout << "Enter a movie title:" << endl;
        getline(cin, deleteMovie);
        movies.deleteMovie(deleteMovie);
        break;
      }
    }
  }
  cout << "Goodbye!" << endl;
}
