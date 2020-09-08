// Driver program
#include "hash.cpp"

vector<string> split (string input, char delimiter)
{
  vector<string> output;
  string word = "";
  input = input + delimiter;
  for (int i = 0; i < input.length(); i++)
  {
    if (input[i] == delimiter)
    {
      if (word.length() != 0)
      {
        output.push_back(word);
      }
      word = "";
    }
    else
    {
      word = word + input[i];
    }
  }
  return output;
}
int main(int argc, char** argv)
{
  HashTable ht(10);
  string line;
  ifstream input;
  input.open(argv[1]);

  if(input.is_open())
  {
    while(input >> line)
    {
      vector<string> words = split(line, ' ');
      for(int i = 0; i < words.size(); i++)
      {
        ht.insert(words[i]);
      }
    }
  }

  input.close();
  ht.printTable();
  cout << "number of collisions: " << ht.getCollsions() << endl;
  cout << "number of unique words: " << ht.getNumItems() << endl;
  cout << "Number of words" << ht.getTotalNumWords() << endl;
  cout << "top 10 words" <<  endl;
  ht.mostFrequent(10);
}
