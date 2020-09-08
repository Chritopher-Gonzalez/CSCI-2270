#include"Graph.cpp"
#include<iostream>
using namespace std;

int main()
{
  Graph graph;
  graph.addVertex("Boulder");
  graph.addVertex("Denver");
  graph.addVertex("Cheyenne");
  graph.addVertex("Fruita");
  graph.addVertex("Moab");
  graph.addVertex("Longmont");
  graph.addVertex("London");
  graph.addVertex("Paris");

  graph.addEdge("Boulder" , "Denver");
  graph.addEdge("Boulder" , "Cheyenne");
  graph.addEdge("Denver" , "Cheyenne");
  graph.addEdge("Fruita" , "Denver");
  graph.addEdge("Longmont" , "Moab");
  graph.addEdge("London" , "Paris");

  graph.breadthFirstTraverse("Boulder");
  cout << endl;

  cout << "Graph is bipartite: " << graph.checkBipartite() << endl;
}
