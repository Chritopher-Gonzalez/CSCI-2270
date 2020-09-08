/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.cpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
	string input;
	bool quit = true;
	ProducerConsumer pc;

	while(quit)
	{
		menu();
		getline(cin, input);

		int menuChoice = stoi(input);
		switch (menuChoice)
		{
			case 1:
			{
				string numItems;
				cout << "Enter the number of items to be produced:" << endl;
				getline(cin, numItems);
				for(int i = 0; i < stoi(numItems); i++)
				{
					string item;
					cout << "Item" << i + 1 << ":" << endl;
					getline(cin, item);
					pc.enqueue(item);
				}
				break;
			}
			case 2:
			{
				string numItems;
				cout << "Enter the number of items to be consumed:" << endl;
				getline(cin, numItems);
				for(int i = 0; i < stoi(numItems); i++)
				{
					if(pc.isEmpty())
					{
						cout<< "No more items to consume from queue" << endl;
						break;
					}
					else
					{
						cout << "Consumed: " << pc.peek() << endl;
						pc.dequeue();
					}
				}
				break;
			}
			case 3:
			{
				cout << "Number of items in the queue:" << pc.queueSize() << endl;
				quit = false;
				break;
			}
		}
	}
}
