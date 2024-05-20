#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

typedef long long ll;

vector<vector<pair<ll, ll>>> graph;
vector<pair<ll, ll>> visited;

int main()
{
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    visited.resize(n + 1, {LONG_LONG_MAX, 0});
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> a >> b;
    multiset<pair<ll, ll>> st;
    st.insert({0, a});
    while (st.size())
    {
        auto it = st.begin();
        ll curTime = it->first;
        ll curVert = it->second;
        st.erase(it);

        if (visited[curVert].first < curTime)
        {
            st.erase(*it);
            continue;
        }
        else if (visited[curVert].first == curTime)
            visited[curVert].second++;
        else
            visited[curVert] = {curTime, 1};

        if (curVert == b)
            continue;

        for (int i = 0; i < graph[curVert].size(); i++)
        {
            ll vert = graph[curVert][i].first;
            ll time = graph[curVert][i].second;

            if (visited[vert].first >= curTime + time)
                st.insert({curTime + time, vert});
        }
    }

    cout << visited[b].second;

    return 0;
}