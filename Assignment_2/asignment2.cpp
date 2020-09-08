#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct wordItem
{
  string word;
  int count;

  wordItem()
  {
    word = "";
    count = 0;
  }
};

void resize(wordItem *&arrayPtr, int &capacity)
{
	// TODO increase the capacity by two times
	int newCapacity = capacity * 2;

	// dynamically allocate an array of size newCapacity
	wordItem *newArray = new wordItem[newCapacity];

	// TODO copy all data from oldArray to newArray
	for(int i = 0; i < capacity; i++)
	{
		newArray[i] = arrayPtr[i];
	}

	// TODO free the memory associated with oldArray
	delete [] arrayPtr;

	arrayPtr = newArray;
	capacity = newCapacity;

}

void getStopWords(const char *ignoreWordFileName, string ignoreWords[])
{
  int i = 0;
  string line;
  ifstream ignoreWordFile;
  ignoreWordFile.open(ignoreWordFileName);

  if(ignoreWordFile.is_open())
  {
    while(getline(ignoreWordFile, line))
    {
      ignoreWords[i] = line;
      i++;
    }
      ignoreWordFile.close();
  }
  else
  {
    cout << "Failed to open " << ignoreWordFileName << endl;
  }
}

bool isStopWord(string word, string ignoreWords[])
{
  for(int i = 0; i < 50; i++)
  {
    if(ignoreWords[i] == word)
    {
      return true;
    }
  }
  return false;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{
  int numWords = 0;
  for(int i = 0; i < length; i++)
  {
    numWords = numWords + uniqueWords[i].count;
  }
  return numWords;
}

void arraySort(wordItem uniqueWords[], int length)
{
  for(int i = 0; i < length; i++)
  {
    for(int j = i + 1; j < length; j++)
    {
      if(uniqueWords[i].count < uniqueWords[j].count)
      {
        wordItem temp = uniqueWords[i];
        uniqueWords[i] = uniqueWords[j];
        uniqueWords[j]= temp;
      }
    }
  }
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords)
{
  for(int i = N; i < N + 10; i++)
  {
    float occurrenceProbability = (float) uniqueWords[i].count / totalNumWords;
    cout << fixed << setprecision(4) << occurrenceProbability << " - " << uniqueWords[i].word << endl;
  }
}

int main(int argc, char** argv)
{
  int capacity = 100;
	int numOfElement = 0;
  wordItem *uniqueWords = new wordItem[capacity];
  int timesDoubled = 0;

  string ignoreWords[50];
  getStopWords(argv[3], ignoreWords);

  string line;

  ifstream input;
  input.open(argv[2]);

  if(input.is_open())
  {
    while(input >> line)
    {
      if(isStopWord(line, ignoreWords) == false)
      {
        bool foundWord = false;

        for(int i = 0; i < numOfElement; i++)
        {
          if(uniqueWords[i].word == line)
          {
            uniqueWords[i].count++;
            foundWord = true;
            break;
          }
        }

        if(foundWord == false)
        {
              wordItem temp;
              temp.word = line;
              temp.count++;
              uniqueWords[numOfElement] = temp;
              numOfElement++;
        }

        if(numOfElement == capacity)
        {
          resize(uniqueWords, capacity);
          timesDoubled++;
        }
      }
    }

    arraySort(uniqueWords, numOfElement);

    cout << "Array doubled: " << timesDoubled << endl;
    cout << "#" << endl;
    cout << "Unique non-common words: " << numOfElement << endl;
    cout << "#" << endl;
    cout << "Total non-common words: " << getTotalNumberNonStopWords(uniqueWords, numOfElement) << endl;
    cout << "#" << endl;
    cout << "Probability of next 10 words from rank " << argv[1] << endl;
    cout << "---------------------------------------" << endl;
    printNext10(uniqueWords, stoi(argv[1]), getTotalNumberNonStopWords(uniqueWords, numOfElement));
    input.close();
  }
}
