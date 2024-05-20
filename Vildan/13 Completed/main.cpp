#include <iostream>
#include <vector>
#include <cmath>
#include <deque>

using namespace std;

class Circle
{
    double x, y, r;

public:
    Circle(double x, double y, double r) : x(x), y(y), r(r) {}
    bool isTouch(const Circle &other)
    {
        return hypot(other.x - x, other.y - y) <= r + other.r;
    }
};

int main()
{
    vector<Circle> circles;
    vector<vector<int>> graph;

    int n;
    cin >> n;
    circles.reserve(n);
    graph.resize(n);
    for (int i = 0; i < n; i++)
    {
        double x, y, r;
        cin >> x >> y >> r;
        Circle circle(x, y, r);
        for (int j = 0; j < circles.size(); j++)
            if (circles[j].isTouch(circle))
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        circles.push_back(circle);
    }

    vector<bool> visited(n);
    int cnt = 0;
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            q.push_back(i);
            while (q.size())
            {
                int c = q.front();
                q.pop_front();
                visited[c] = true;
                for (int i = 0; i < graph[c].size(); i++)
                    if (!visited[graph[c][i]])
                        q.push_back(graph[c][i]);
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}