// Ankit Vishwakarma 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph, int src, vector<int>& color) {
    queue<int> q;
    q.push(src);
    color[src] = 1; // Start coloring src with color 1

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Check all adjacent vertices
        for (int v : graph[u]) {
            // If the adjacent vertex is not colored, color it with the alternate color
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            }
            // If the adjacent vertex has the same color, then the graph is not bipartite
            else if (color[v] == color[u]) {
                return false;
            }
        }
    }

    return true;
}

bool checkBipartite(vector<vector<int>>& graph, int V) {
    vector<int> color(V, -1); // Initialize all vertices as uncolored

    // Check for each vertex, since the graph might be disconnected
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!isBipartite(graph, i, color)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V);

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (checkBipartite(graph, V)) {
        cout << "The graph is bipartite (can be bicolored).\n";
    } else {
        cout << "The graph is not bipartite (cannot be bicolored).\n";
    }

    return 0;
}
