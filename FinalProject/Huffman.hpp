#ifndef Huffman_HPP
#define Huffman_HPP

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

struct Node {
    int frequency;
		char data;
		//bool code;
    Node* left;
    Node* right;
    Node(int frequency, char data) {
        this->frequency = frequency;
        this->data = data;
    }
		Node(int frequency, char data, Node* left, Node* right) {
        this->frequency = frequency;
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Huffman {
    private:
        Node* root;
        map<char,int> frequencyTable;
        map<char, int> codeTable;

    public:
         //Huffman();
        //~Huffman();
        void getFrequencies(string filename);
        void printTable();
        void buildTree();
        void print2DUtil(Node *root, int space);
        char findCharacter(int frequency);
};


#endif
