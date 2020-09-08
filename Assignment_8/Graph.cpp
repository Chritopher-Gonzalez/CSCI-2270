#include"Graph.hpp"
#include <queue>
#include<iostream>
using namespace std;

void Graph::addEdge(string v1, string v2)
{
  //searches for each first vertex
  for(int i = 0; i < vertices.size(); i++)
  {
    //if found
    if(vertices[i]->name == v1)
    {
      //searches for next node
      for(int j = 0; j < vertices.size(); j++)
      {
        //if found
        if(vertices[j]->name == v2 )
        {
          //establishes first edge
          adjVertex newEdge1;
          newEdge1.v = vertices[j];
          vertices[i]->adj.push_back(newEdge1);
          //another vertex for edge in other direction
          adjVertex newEdge2;
          newEdge2.v = vertices[i];
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
      cout << vertices[i]->adj[j].v->name << " ";
    }
    cout << endl;
  }
}
void Graph::breadthFirstTraverse(string sourceVertex)
{
  // Need to find the source vertex since we only have it's name
  // A pointer for source vertex
  vertex *vStart;
  for(unsigned int i = 0; i < vertices.size(); i++)
  {
      if(vertices[i]->name == sourceVertex)
      {
          vStart = vertices[i];
          vStart->visited = true;
      }
  }
  // Use the queue to keep track of visited vertices
  queue<vertex*> q;
  // Enqueue the source vertex
  q.push(vStart);
  vertex *n;
  int timesPrinted = 0;
  cout << "Starting vertex (root): " ;
  // standard BFS
  while(!q.empty())
  {
    n = q.front();
    if(timesPrinted == 0)
    {
     cout << n->name << "-> ";
    }
    else
    {
       cout << n->name << "(" << n->distance << ") ";
    }
    timesPrinted++;
    q.pop();
    // go to all the adjacent vertices of n
    for(unsigned int i = 0; i < n->adj.size(); i++)
    {
      // If a adjacent has not been visited
      if(n->adj[i].v->visited == false)
      {
        // then mark it visited
        n->adj[i].v->visited = true;
        n->adj[i].v->distance = n->distance + 1;
        q.push(n->adj[i].v);
      }
    }
  }
}
void DFTraversal(vertex* currNode)
{
  //mark current node as visted
  currNode->visited = true;
  //recur through all adjacent vertex
  for(unsigned int i = 0; i < currNode->adj.size(); i++)
  {
    if(currNode->adj[i].v->visited == false)
    {
      DFTraversal(currNode->adj[i].v);
    }
  }
}
int Graph::getConnectedComponents()
{
  int components = 0;
  //mark all vertices as not visted
  for(unsigned int i = 0; i < vertices.size(); i++)
  {
    vertices[i]->visited = false;
  }
  //count number of unconected graphs
  for(unsigned int i = 0; i < vertices.size(); i++)
  {
    if(vertices[i]->visited == false)
    {
      DFTraversal(vertices[i]);
      components++;
    }
  }
  return components;
}
bool Graph::checkBipartite()
{
  //mark all vectors as not visted
  for(unsigned int i = 0; i < vertices.size(); i++)
  {
    vertices[i]->visited = false;
  }
  for(unsigned int i = 0; i < vertices.size(); i++)
  {
    if(!vertices[i]->visited)
    {
      //assing the first color to node
      if(vertices[i]->color == "")
      {
        vertices[i]->color =  "black";
      }
      //queue for breadthFirstTraverse
      queue<vertex*> q;
      vertex *n;
      q.push(vertices[i]);
      //run while there are vertices
      while(!q.empty())
      {
        //vertex to be looked at
        n = q.front();
        q.pop();
        for(unsigned int i = 0; i < n->adj.size(); i++)
        {
          //if node doesnt have color
          if(n->adj[i].v->color == "")
          {
            if(n->color == "black")
            {
              n->adj[i].v->color = "red";
            }
            else
            {
              n->adj[i].v->color = "black";
            }
          }

          //if adjecent color is equal to current color then not bipartite
          else if(n->color == n->adj[i].v->color)
          {
            return false;
          }
          // mark as visted
          if(n->adj[i].v->visited == false)
          {
            // mark it visited
            n->adj[i].v->visited = true;
            q.push(n->adj[i].v);
          }
        }
      }
    }
  }
  return true;
}
