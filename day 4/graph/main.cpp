#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_NODES = 11; // 10 nodes (1-10), so size 11 to ignore index 0

class Graph {
    int adjMatrix[MAX_NODES][MAX_NODES];
    bool visited[MAX_NODES];
    int numNodes;

public:
    Graph(int n) {
        numNodes = n;
        // Initialize matrix with 0
        for (int i = 0; i <= numNodes; i++) {
            for (int j = 0; j <= numNodes; j++) {
                adjMatrix[i][j] = 0;
            }
            visited[i] = false;
        }
    }

    // Add Undirected Edge
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    // 1. Display Adjacency Matrix
    void printMatrix() {
        cout << "--- Adjacency Matrix ---" << endl;
        cout << "   ";
        for (int i = 1; i <= numNodes; i++) cout << i << " ";
        cout << endl;

        for (int i = 1; i <= numNodes; i++) {
            cout << i << ": ";
            for (int j = 1; j <= numNodes; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // 2. BFS Implementation
    void BFS(int startNode) {
        // Reset visited array for fresh traversal
        fill(visited, visited + MAX_NODES, false);

        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            // Check all neighbors
            for (int i = 1; i <= numNodes; i++) {
                // If there is an edge and it's not visited
                if (adjMatrix[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    // Helper function for DFS recursion
    void DFS_Recursive(int v) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 1; i <= numNodes; i++) {
            if (adjMatrix[v][i] == 1 && !visited[i]) {
                DFS_Recursive(i);
            }
        }
    }

    // 3. DFS Wrapper
    void DFS(int startNode) {
        // Reset visited array
        fill(visited, visited + MAX_NODES, false);

        cout << "DFS Traversal: ";
        DFS_Recursive(startNode);
        cout << endl;
    }
};

int main() {
    // Create graph with 10 nodes
    Graph g(10);

    // Adding edges based on your image
    g.addEdge(1, 2);
    g.addEdge(1, 4);

    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 7);
    g.addEdge(2, 8);

    g.addEdge(3, 4);
    g.addEdge(3, 9);
    g.addEdge(3, 10);

    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(5, 8);

    g.addEdge(7, 8);

    // 1. Print Matrix
    g.printMatrix();

    // 2. BFS starting from Node 1
    g.BFS(1);

    // 3. DFS starting from Node 1
    g.DFS(1);

    return 0;
}
