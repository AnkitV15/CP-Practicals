// Ankit Vishwakarma 
#include <iostream>
#include <vector>
#include <list> // For adjacency list representation

using namespace std;

// Function to add an edge to an undirected graph
void addEdge(list<int>* adj, int src, int dest) {
  adj[src].push_back(dest);
  adj[dest].push_back(src); // For undirected graphs
}

// Recursive DFS traversal function
void DFSUtil(list<int>* adj, vector<bool>& visited, int v) {
  visited[v] = true;
  cout << v << " "; // Process the current vertex

  // Recur for all unvisited adjacent vertices
  for (int neighbor : adj[v]) {
    if (!visited[neighbor])
      DFSUtil(adj, visited, neighbor);
  }
}

// Main DFS function that initiates the traversal from the source vertex
void DFS(list<int>* adj, int V) {
  vector<bool> visited(V, false); // Keep track of visited vertices

  // Call the recursive helper function to start DFS traversal from each
  // unvisited vertex (to handle disconnected graphs)
  for (int i = 0; i < V; i++)
    if (!visited[i])
      DFSUtil(adj, visited, i);
}

int main() {
  int V = 5; // Number of vertices
  list<int>* adj = new list<int>[V]; // Create adjacency list

  // Add edges for a sample graph
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 1, 2);
  addEdge(adj, 3, 4);

  cout << "Depth First Traversal (starting from vertex 0): ";
  DFS(adj, V);

  return 0;
}
