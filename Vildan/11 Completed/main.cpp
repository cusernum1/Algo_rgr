#include <iostream>
#include <map>

using namespace std;

class SparseMatrix
{
    int n, m;
    map<pair<int, int>, double> matrix;
public:
    SparseMatrix(int n, int m) : n(n), m(m) {}
    double get(int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            throw runtime_error("Invalid index");

        if (matrix.count({i, j}))
            return matrix[{i, j}];
        return 0;
    }
    void set(int i, int j, int v)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            throw runtime_error("Invalid index");
        if (v == 0)
            matrix.erase({i, j});
        else
            matrix[{i, j}] = v;
    }
};

int main()
{

    return 0;
}