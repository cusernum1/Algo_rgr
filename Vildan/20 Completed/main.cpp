#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

vector<int> generate_vector()
{
    vector<int> ans;
    for (int i = 0; i < 1e6; i++)
        ans.push_back(rand());
    return ans;
}

int test(vector<int> &arr)
{
    std::chrono::steady_clock::time_point begin, end;
    begin = std::chrono::steady_clock::now();

    sort(arr.begin(), arr.end());
    // stable_sort(arr.begin(), arr.end());
    // make_heap(arr.begin(), arr.end());
    // sort_heap(arr.begin(), arr.end());

    end = std::chrono::steady_clock::now();

    return chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
}

int main()
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        vector<int> arr = generate_vector();
        int cnt = test(arr);
        sum += cnt;
    }
    cout << "Avarage: " << sum / 10 << '\n';

    return 0;
}