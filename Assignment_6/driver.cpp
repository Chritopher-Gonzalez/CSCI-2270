#include "MovieTree.cpp"
#include <iostream>
using namespace std;

void displayMenu()
{
  cout << "======Main Menu======" << endl;
  cout << "1. Find a movie" << endl;
  cout << "2. Query movies" << endl;
  cout << "3. Print the inventory" << endl;
  cout << "4. Average Rating of movies" << endl;
  cout << "5. Quit" << endl;
}

int main (int argc, char* argv[])
{
  MovieTree movies;
  string input, line;
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
      movies.addMovieNode(stoi(ranking), title, stoi(year), stof(rating));
    }
    //close file
    file.close();
  }

  while(input != "5")
  {
    displayMenu();
    getline(cin, input);
    int menuChoice = stoi(input);
    switch (menuChoice)
    {
      //find movie
      case 1:
      {
        string title;
        cout << "Enter title:" << endl;
        getline(cin, title);
        movies.findMovie(title);
        break;
      }
      //find movies with rating and year requirment
      case 2:
      {
        string rating;
        string year;
        cout << "Enter minimum rating:" << endl;
        getline(cin, rating);
        cout << "Enter minimum year:" << endl;
        getline(cin, year);
        movies.queryMovies(stof(rating), stoi(year));
        break;
      }
      //print movie catlog
      case 3:
      {
        movies.printMovieInventory();
        break;
      }
      //print average rating of current movies
      case 4:
      {
        movies.averageRating();
        break;
      }
    }
  }

  cout << "Goodbye!" << endl;
}
