#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

void create(int size, set<string> &st, unordered_set<string> &u_st, vector<string> &tests)
{
    for (int i = 0; i < size; i++)
    {
        int num = rand() % (int)1e9;
        st.insert(num);
        u_st.insert(num);
        if (tests.size() < 50)
            tests.push_back(num);
        s.clear();
    }
    for (int i = 0; i < 50; i++)
        tests.push_back(rand());
}

void check_speed(set<string> &st, unordered_set<string> &u_st, vector<string> &tests)
{
    std::chrono::steady_clock::time_point begin, end;
    long long unset_count = 0, set_count = 0;
    for (int i = 0; i < tests.size(); i++)
    {
        begin = std::chrono::steady_clock::now();
        st.find(tests[i]);
        end = std::chrono::steady_clock::now();
        set_count += chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    }

    for (int i = 0; i < tests.size(); i++)
    {
        begin = std::chrono::steady_clock::now();
        u_st.find(tests[i]);
        end = std::chrono::steady_clock::now();
        unset_count += chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    }

    cout << "set: " << set_count / tests.size() << '\n';
    cout << "unordered_set: " << unset_count / tests.size() << '\n';
}

int main()
{
    srand(time(nullptr));

    set<string> st;
    unordered_set<string> u_st;
    vector<string> tests;
    int size = 100;

    cout << "size: " << size << '\n';

    create(size, st, u_st, tests);
    check_speed(st, u_st, tests);

    st.clear();
    u_st.clear();
    tests.clear();

    size = (int)1e4;
    cout << "size: " << size << '\n';

    create(size, st, u_st, tests);
    check_speed(st, u_st, tests);

    st.clear();
    u_st.clear();
    tests.clear();

    size = (int)1e6;
    cout << "size: " << size << '\n';

    create(size, st, u_st, tests);
    check_speed(st, u_st, tests);

    st.clear();
    u_st.clear();
    tests.clear();

    size = (int)1e7;
    cout << "size: " << size << '\n';

    create(size, st, u_st, tests);
    check_speed(st, u_st, tests);

    st.clear();
    u_st.clear();
    tests.clear();

    return 0;
}