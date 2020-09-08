#include"Graph.hpp"
#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

void DFTraversal(vertex* currNode)
{
  //mark current node as visted
  currNode->visited = true;
  cout << currNode->name << " --> ";
  //recur through all adjacent vertex
  for(unsigned int i = 0; i < currNode->adj.size(); i++)
  {
    if(currNode->adj[i].v->visited == false)
    {
      DFTraversal(currNode->adj[i].v);
    }
  }
}
int search(string name, vector<vertex*> vertices)
{
  int sourceIndex;
  bool sourceFound = false;
  for(unsigned int i = 0; i < vertices.size() && !sourceFound; i++)
  {
    if(vertices[i]->name == name)
    {
      sourceIndex = i;
      sourceFound = true;
    }
  }
  return sourceIndex;
}
void Graph::addEdge(string v1, string v2, int num)
{
  //searches for each first vertex
  for(unsigned int i = 0; i < vertices.size(); i++)
  {
    //if found
    if(vertices[i]->name == v1)
    {
      //searches for next node
      for(unsigned int j = 0; j < vertices.size(); j++)
      {
        //if found
        if(vertices[j]->name == v2 )
        {
          //establishes first edge
          adjVertex newEdge1;
          newEdge1.v = vertices[j];
          newEdge1.weight = num;
          vertices[i]->adj.push_back(newEdge1);
          //another vertex for edge in other direction
          adjVertex newEdge2;
          newEdge2.v = vertices[i];
          newEdge2.weight = num;
          vertices[j]->adj.push_back(newEdge2);
        }
      }
    }
  }
}
void Graph::addVertex(string name)
{
  vertex * v = new vertex;
  v->name = name;
  vertices.push_back(v);
}
void Graph::displayEdges()
{
  for(unsigned int i = 0; i < vertices.size(); i++)
  {
    cout << vertices[i]->name << " --> ";
    for(unsigned int j = 0; j < vertices[i]->adj.size(); j++)
    {
      cout << vertices[i]->adj[j].v->name << " " << vertices[i]->adj[j].weight << " "  ;
    }
    cout << endl;
  }
}
void Graph::depthFirstTraversal(string sourceVertex)
{
  int sourceIndex = search(sourceVertex, vertices);
  DFTraversal(vertices[sourceIndex]);
  cout << "Done";

}
vertex* Graph::DijkstraAlgorithm(string start, string end)
{
  vector<vertex*> solved;
  vertex* vStart = vertices[search(start, vertices)];
  vertex* vEnd = vertices[search(end, vertices)];
  vStart->visited = true;
  vStart->distance = 0;
  solved.push_back(vStart);

  while(!vEnd->visited)
  {
    int minDistance = INT_MAX;
    vertex* temp = new vertex;
    vertex* parent = new vertex;
    for(unsigned int i = 0; i < solved.size(); i++)
    {
      for(unsigned int j = 0; j < solved[i]->adj.size(); j++)
      {
        int dist;
        if(!solved[i]->adj[j].v->visited)
        {
          dist = solved[i]->distance + solved[i]->adj[j].weight;
          if(dist < minDistance)
          {
            temp = solved[i]->adj[j].v;
            minDistance = dist;
            parent = solved[i];

          }
        }
      }
    }
    temp->distance = minDistance;
    temp->pred = parent;
    temp->visited = true;
    solved.push_back(temp);
  }
  return vEnd;
}
void Graph::shortestpath(string start, string end)
{
  vertex* temp = vertices[search(end, vertices)];
  stack <string> path;
  while(!temp)
  {
    path.push(temp->name);
    temp = temp->pred;
  }
  while(!path.empty())
  {
    cout << path.top() << " ";
    path.pop();
  }
}
void Graph::setAllVerticesUnvisited()
{
  for(unsigned int i = 0; i < vertices.size(); i++)
  {
    vertices[i]->visited = false;
  }
}
