#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Matrix
{
    vector<double> v;
    int n, m;

public:
    Matrix(int n, int m) : n(n), m(m)
    {
        v.resize(n * m);
    }
    double &operator[](pair<int, int> index)
    {
        auto [i, j] = index;
        if (i < 0 || i > n || j < 0 || j > m)
            throw runtime_error("Invalid Index");

        return v[i * n + j];
    }
    Matrix operator+(const Matrix &other)
    {
        if (n != other.n || m != other.m)
            throw runtime_error("Invalid Sizes");

        Matrix answer(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                answer[{i, j}] = v[i * n + j] + other.v[i * n + j];
        return answer;
    }
};

int main()
{
    Matrix m(1000, 1000), m2(1000, 1000);
    long long cnt = 0;
    for (int i = 0; i < 100; i++)
    {
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
        Matrix ans = m + m2;
        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        cnt += chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    }
    cout << cnt / 100 << " microseconds\n";
    return 0;
}