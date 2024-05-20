#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> m;
    pair<int, int> ans = {1, 0};

    int i = 0, j = 0;
    while (j < n)
    {
        if (m[arr[j]] == 0)
        {
            m[arr[j++]]++;
            if (j - i > ans.first)
                ans = {j - i, i};
        }
        else
            m[arr[i++]]--;
    }

    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}