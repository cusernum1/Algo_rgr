#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool hasCycleDFS(int v, vector<vector<int>>& graph, vector<bool>& visited, unordered_set<int>& recStack) {
    visited[v] = true;
    recStack.insert(v);

    for (int neighbor : graph[v]) {
        if (!visited[neighbor] && hasCycleDFS(neighbor, graph, visited, recStack))
            return true;
        else if (recStack.count(neighbor))
            return true;
    }

    recStack.erase(v);
    return false;
}

bool hasCycle(vector<vector<int>>& graph, int numVertices) {
    vector<bool> visited(numVertices, false);
    unordered_set<int> recStack;

    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i] && hasCycleDFS(i, graph, visited, recStack))
            return true;
    }

    return false;
}
