#include "Huffman.hpp"

void Huffman::getFrequencies(string filename) {
	ifstream file(filename);
	if (!file.is_open())
		return;
	string line = "";
	while (getline(file,line)) {
		for (int i = 0; i < line.size(); i++) {
			if (frequencyTable.count(line[i]) > 0) {
				frequencyTable[line[i]]++;
			} else {
				frequencyTable[line[i]] = 1;
			}
		}
	}
	file.close();
}

void Huffman::printTable() {
	for (char i = 32; i < 126; i++) {
		if (frequencyTable.count(i) > 0) {
			cout << i << ": " << frequencyTable[i] << endl;
		}
	}
}

// helper function to print tree - stolen from recitation - used for debug purposes
void printTreeHelper(Node* currNode){
     if(currNode)
     {
        printTreeHelper( currNode->left);
        cout << " "<< currNode->data;
        printTreeHelper( currNode->right);
     }
 }
void Huffman::print2DUtil(Node *root, int space)
{
	printTreeHelper(root);
	cout<<endl;
}

// helper function that returns the character given a frequency
char Huffman::findCharacter(int frequency) {
	for (char i = 32; i < 126; i++) {
		if (frequencyTable[i] == frequency) {
			frequencyTable.erase(i);
			return frequencyTable[i];
		}
	}
}

// cd documents\atom\csci-2270\project && g++ -std=c++11 huffman_testing.cpp
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		return (l->frequency > r->frequency);
	}
};
void Huffman::buildTree() {

	priority_queue <Node*, vector<Node*>, comp> priorityQueue;

	for(auto pair: frequencyTable)
	{
		Node* temp = new Node(pair.second, pair.first, NULL, NULL);
		priorityQueue.push(temp);
	}
	while(priorityQueue.size() != 1)
	{
		Node* left = priorityQueue.top();
		priorityQueue.pop();
		Node* right = priorityQueue.top();
		priorityQueue.pop();

		int sum = left->frequency + right->frequency;
		Node* temp = new Node(sum, '*', left, right);
		priorityQueue.push(temp);
	}
	root = priorityQueue.top();
	print2DUtil(root, 0);
}
void decode(string)
