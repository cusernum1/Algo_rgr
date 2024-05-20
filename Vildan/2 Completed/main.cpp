#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> in, out;
    for (int i = 2; i <= n; i++)
        in.push(i);

    while (in.size())
    {
        int p = in.front();
        in.pop();

        cout << p << ' ';

        int cnt = in.size();
        for (int i = 0; i < cnt; i++)
        {
            int num = in.front();
            in.pop();
            if (num % p != 0)
                out.push(num);
        }

        in.swap(out);
    }

    return 0;
}