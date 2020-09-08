#include "Huffman.cpp"

int main() {
    Huffman HuffmanTree;
    HuffmanTree.getFrequencies("sample.txt");
    HuffmanTree.printTable();
    HuffmanTree.buildTree();
    return 0;
}
