#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node, vector<int> adj[], bool visited[]) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];

        if (!visited[next]) {
            DFS(next, adj, visited);
        }
    }
}

void BFS(int start, vector<int> adj[], bool visited[]) {
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < adj[node].size(); i++) {
            int next = adj[node][i];

            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of buildings and roads: ";
    cin >> n >> e;

    vector<int> adj[n];

    cout << "Enter roads (two connected buildings):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting building: ";
    cin >> start;

    bool visited1[n] = {false};
    bool visited2[n] = {false};

    cout << "DFS Traversal: ";
    DFS(start, adj, visited1);

    cout << "\nBFS Traversal: ";
    BFS(start, adj, visited2);

    return 0;
}
