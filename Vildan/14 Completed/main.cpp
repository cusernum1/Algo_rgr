#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> di{2, 2, 1, 1, -1, -1, -2, -2};
vector<int> dj{1, -1, 2, -2, 2, -2, 1, -1};

int main()
{
    vector<string> arr(8);
    for (int i = 0; i < 8; i++)
        cin >> arr[i];
    deque<pair<int, int>> q;
    vector<vector<int>> ans(8, vector<int>(8));
    q.push_back({0, 0});
    while (q.size())
    {
        pair<int, int> p = q.front();
        q.pop_front();
        for (int j = 0; j < di.size(); j++)
        {
            int ni = p.first + di[j];
            int nj = p.second + dj[j];
            if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8 && arr[ni][nj] == '.' && !ans[ni][nj])
            {
                ans[ni][nj] = ans[p.first][p.second] + 1;
                q.push_back({ni, nj});
            }
        }
    }

    if (ans[7][7])
        cout << "YES " << ans[7][7];
    else
        cout << "NO";

    return 0;
}