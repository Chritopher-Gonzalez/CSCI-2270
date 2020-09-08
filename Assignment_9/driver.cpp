#include"Graph.cpp"
#include<iostream>
using namespace std;

int main()
{
  Graph g;
  g.addVertex("Amsterdam");
  g.addVertex("Broomfield");
  g.addVertex("Calcutta");
  g.addVertex("Dallas");
  g.addVertex("Fabens");

  g.addEdge("Amsterdam", "Broomfield", 10);
  g.addEdge("Amsterdam", "Calcutta", 30);
  g.addEdge("Broomfield", "Calcutta", 10);
  g.addEdge("Broomfield", "Fabens", 50);
  g.addEdge("Calcutta", "Dallas", 5);
  g.addEdge("Dallas", "Fabens", 5);

  g.displayEdges();

  vertex* temp = g.DijkstraAlgorithm("Amsterdam", "Fabens");
  g.setAllVerticesUnvisited();
  cout << "2." << endl;
  DFTraversal(temp);
}
