#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool helper(int i, vector<vector<int>> &graph, vector<int> &visited)
{
    if (visited[i] == 1)
        return true;

    visited[i] = 1;
    for (int j = 0; j < graph[j].size(); j++)
        if (helper(graph[i][j], graph, visited))
            return true;
    visited[i] = 2;
    return false;
}

bool checkCycle(vector<vector<int>> &graph)
{
    vector<int> visited(graph.size());
    for (int i = 0; i < visited.size(); i++)
        if (!visited[i] && helper(i, graph, visited))
            return true;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    cout << checkCycle(graph);

    return 0;
}