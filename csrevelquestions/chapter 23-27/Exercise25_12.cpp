#include <iostream>
#include <string>
#include <vector>

#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include "Graph.h"
#include "WeightedEdge.h" // Defined in Listing 25.1 
#include "MST.h" // Defined in Listing 25.3
#include "ShortestPathTree.h" // Defined in Listing 25.8  
#include <queue> // For priority_queue
#include <functional> // For the greater operator in VC++ 2012

using namespace std;

template<typename V>
class WeightedGraph : public Graph<V>
{
public:
  // Construct an empty graph 
  WeightedGraph();

  // Construct a graph from vertices and edges objects 
  WeightedGraph(vector<V>& vertices, vector<WeightedEdge>& edges);

  // Construct a graph with vertices 0, 1, ..., n-1 and
  // edges in a vector 
  WeightedGraph(int numberOfVertices, vector<WeightedEdge>& edges);

  // Print all edges in the weighted tree 
  void WeightedGraph<V>::printWeightedEdges();

  // Adds a vertex to the graph
  bool addVertex(V v);

  // Add a weighted edge 
  void addEdge(int u, int v, double w);
  
  // Get a minimum spanning tree rooted at vertex 0 
  MST getMinimumSpanningTree();

  // Get a minimum spanning tree rooted at a specified vertex 
  MST getMinimumSpanningTree(int startingVertex);

  // Find single-source shortest paths 
  ShortestPathTree getShortestPath(int sourceVertex);

private:
  // Priority adjacency lists on edge weights 
  vector<priority_queue<WeightedEdge, vector<WeightedEdge>,
    greater<WeightedEdge>>> queues;

  // Return true if v is in vector T 
  bool contains(vector<int>& T, int v);
};

const int INFINITY = 2147483647;

template<typename V>
WeightedGraph<V>::WeightedGraph()
{
}

template<typename V>
WeightedGraph<V>::WeightedGraph(vector<V>& vertices,
  vector<WeightedEdge>& edges)
{
  // Add vertices to the graph
  for (unsigned i = 0; i < vertices.size(); i++)
  {
    addVertex(vertices[i]); 
  }

  // Add edges to the graph
  for (unsigned i = 0; i < edges.size(); i++)
  {
    addEdge(edges[i].u, edges[i].v, edges[i].weight);
  }
}

template<typename V>
WeightedGraph<V>::WeightedGraph(int numberOfVertices,
  vector<WeightedEdge>& edges)
{
  // Add vertices to the graph
  for (int i = 0; i < numberOfVertices; i++)
    addVertex(i); // vertices is {0, 1, 2, ..., n-1}

  // Add edges to the graph
  for (unsigned i = 0; i < edges.size(); i++)
  {
    addEdge(edges[i].u, edges[i].v, edges[i].weight);
  }
}

template<typename V>
void WeightedGraph<V>::printWeightedEdges()
{
  for (unsigned i = 0; i < queues.size(); i++)
  {
    // Display all edges adjacent to vertex with index i
    cout << "Vertex " << i << ": ";

    // Get a copy of queues[i], so as to keep original queue intact
    priority_queue<WeightedEdge, vector<WeightedEdge>,
      greater<WeightedEdge> > pQueue = queues[i];
    while (!pQueue.empty())
    {
      WeightedEdge edge = pQueue.top();
      pQueue.pop();
      cout << "(" << edge.u << ", " << edge.v << ", "
        << edge.weight << ") ";
    }
    cout << endl;
  }
}

template<typename V>
bool WeightedGraph<V>::addVertex(V v)
{
  if (Graph::addVertex(v)) 
  {
    queues.push_back(priority_queue<WeightedEdge,
      vector<WeightedEdge>, greater<WeightedEdge>>());
    return true; 
  }
  else
  {
    return false; 
  }
}

template<typename V>
void WeightedGraph<V>::addEdge(int u, int v, double w)
{
  if (Graph::addEdge(u, v)) 
  {
    queues[u].push(WeightedEdge(u, v, w));
  }
}

template<typename V>
MST WeightedGraph<V>::getMinimumSpanningTree()
{
  return getMinimumSpanningTree(0);
}

template<typename V>
MST WeightedGraph<V>::getMinimumSpanningTree(int startingVertex)
{
  vector<int> T;
  // T initially contains the startingVertex;
  T.push_back(startingVertex);

  unsigned numberOfVertices = vertices.size(); // Number of vertices
  vector<int> parent(numberOfVertices); // Parent of a vertex
  // Initially set the parent of all vertices to -1
  for (unsigned i = 0; i < parent.size(); i++)
    parent[i] = -1;
  double totalWeight = 0; // Total weight of the tree thus far

  // Clone the queue, so as to keep the original queue intact
  vector<priority_queue<WeightedEdge, vector<WeightedEdge>,
    greater<WeightedEdge> > > queues = this->queues;

  // All vertices are found?
  while (T.size() < numberOfVertices)
  {
    // Search for the vertex with the smallest edge adjacent to
    // a vertex in T
    int v = -1;
    double smallestWeight = INFINITY;
    for (unsigned i = 0; i < T.size(); i++)
    {
      int u = T[i];
      while (!queues[u].empty() && contains(T, queues[u].top().v))
      {
        // Remove the edge from queues[u] if the adjacent
        // vertex of u is already in T
        queues[u].pop();
      }

      if (queues[u].empty())
        continue; // Consider the next vertex in T

      // Current smallest weight on an edge adjacent to u
      WeightedEdge edge = queues[u].top();
      if (edge.weight < smallestWeight)
      {
        v = edge.v;
        smallestWeight = edge.weight;
        // If v is added to the tree, u will be its parent
        parent[v] = u;
      }
    } // End of for

    T.push_back(v); // Add a new vertex to the tree
    totalWeight += smallestWeight;
  } // End of while

  return MST(startingVertex, parent, T, totalWeight);
}

template<typename V>
bool WeightedGraph<V>::contains(vector<int>& V, int v)
{
  for (unsigned i = 0; i < V.size(); i++)
  {
    if (V[i] == v) return true;
  }

  return false;
}

template<typename V>
ShortestPathTree WeightedGraph<V>::getShortestPath(int sourceVertex)
{
  // T stores the vertices whose path found so far
  vector<int> T;
  // T initially contains the sourceVertex;
  T.push_back(sourceVertex);

  // parent[v] stores the previous vertex of v in the path
  vector<int> parent(getSize());
  parent[sourceVertex] = -1; // The parent of source is set to -1

  // cost[v] stores the cost of the path from v to the source
  vector<double> cost(getSize());
  for (unsigned i = 0; i < cost.size(); i++)
  {
    cost[i] = INFINITY; // Initial cost set to infinity
  }
  cost[sourceVertex] = 0; // Cost of source is 0

  // Clone the queue, so as to keep the original queue intact
  vector<priority_queue<WeightedEdge, vector<WeightedEdge>,
    greater<WeightedEdge>>> queues = this->queues;

  // Set cost for the neighbors of sourceVertex
  while (!queues[sourceVertex].empty()) 
  {
    WeightedEdge e = queues[sourceVertex].top();
    queues[sourceVertex].pop();
    cost[e.v] = e.weight;
    parent[e.v] = sourceVertex;
  }

  // Expand T
  while (T.size() < getSize())
  {
    // Find smallest cost v in V - T 
    int u = -1; // Vertex to be determined
    double currentMinCost = INFINITY;
    for (int i = 0; i < getSize(); i++) 
    {
      if (!contains(T, i) && cost[i] < currentMinCost)
      {
        currentMinCost = cost[i];
        u = i;
      }
    }

    if (u != -1) 
    {
      T.push_back(u); // Add a new vertex to T
        
      // Adjust cost[v] for v that is adjacent to u and v in V - T
      while (!queues[u].empty())
      {
        WeightedEdge e = queues[u].top();
        queues[u].pop();
        if (!contains(T, e.v) && cost[e.v] > cost[u] + e.weight)
        {
          cost[e.v] = cost[u] + e.weight;
          parent[e.v] = u; 
        }
      }
    }
    else 
      break; // s cannot reach to all vertices
  } // End of while

  // Create a ShortestPathTree
  return ShortestPathTree(sourceVertex, parent, T, cost);
}

#endif 

// Print paths from all vertices to the source 
template<typename T>
void printAllPaths(ShortestPathTree& tree, vector<T> vertices)
{
  cout << "All shortest paths from " <<
    vertices[tree.getRoot()] << " are:" << endl;
  for (unsigned i = 0; i < vertices.size(); i++)
  {
    cout << "To " << vertices[i] << ": ";

    // Print a path from i to the source
    vector<int> path = tree.getPath(i);
    for (int j = path.size() - 1; j >= 0; j--)
    {
      cout << vertices[path[j]] << " ";
    }

    cout << "(cost: " << tree.getCost(i) << ")" << endl;
  }
}

// Print tree 
template<typename T>
void printTree(Tree& tree, vector<T>& vertices)
{
  cout << "\nThe root is " << vertices[tree.getRoot()];
  cout << "\nThe edges are: ";
  for (unsigned i = 0; i < vertices.size(); i++)
  {
    if (tree.getParent(i) != -1)
      cout << " (" << vertices[i] << ", "
        << vertices[tree.getParent(i)] << ")";
  }
  cout << endl;
}

int main()
{
  // Vertices for graph in Figure 24.1
  string vertices[] = {"Seattle", "San Francisco", "Los Angeles",
    "Denver", "Kansas City", "Chicago", "Boston", "New York",
    "Atlanta", "Miami", "Dallas", "Houston"};

  // Edge array for graph in Figure 24.1
  int edges[][3] = {
    {0, 1, 807}, {0, 3, 1331}, {0, 5, 2097},
    {1, 0, 807}, {1, 2, 381}, {1, 3, 1267},
    {2, 1, 381}, {2, 3, 1015}, {2, 4, 1663}, {2, 10, 1435},
    {3, 0, 1331}, {3, 1, 1267}, {3, 2, 1015}, {3, 4, 599},
      {3, 5, 1003},
    {4, 2, 1663}, {4, 3, 599}, {4, 5, 533}, {4, 7, 1260},
      {4, 8, 864}, {4, 10, 496},
    {5, 0, 2097}, {5, 3, 1003}, {5, 4, 533},
      {5, 6, 983}, {5, 7, 787},
    {6, 5, 983}, {6, 7, 214},
    {7, 4, 1260}, {7, 5, 787}, {7, 6, 214}, {7, 8, 888},
    {8, 4, 864}, {8, 7, 888}, {8, 9, 661},
      {8, 10, 781}, {8, 11, 810},
    {9, 8, 661}, {9, 11, 1187},
    {10, 2, 1435}, {10, 4, 496}, {10, 8, 781}, {10, 11, 239},
    {11, 8, 810}, {11, 9, 1187}, {11, 10, 239}
  };

  // 23 undirected edges in Figure 25.1
  const int NUMBER_OF_EDGES = 46; 

  // Create a vector for vertices
  vector<string> vectorOfVertices(12);
  copy(vertices, vertices + 12, vectorOfVertices.begin());

  // Create a vector for edges
  vector<WeightedEdge> edgeVector;
  for (int i = 0; i < NUMBER_OF_EDGES; i++)
    edgeVector.push_back(WeightedEdge(edges[i][0],
    edges[i][1], edges[i][2]));

  WeightedGraph<string> graph1(vectorOfVertices, edgeVector);
  MST tree1 = graph1.getMinimumSpanningTree();
  cout << "The spanning tree weight is " << tree1.getTotalWeight();
  printTree<string>(tree1, graph1.getVertices());

  ShortestPathTree tree = 
    graph1.getShortestPath(5);
  printAllPaths<string>(tree, graph1.getVertices());

  return 0;
}
