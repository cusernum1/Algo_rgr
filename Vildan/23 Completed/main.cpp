#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    double x, y;
    double len() const { return hypot(x, y); }
    Point operator-(Point p) const
    {
        return {x - p.x, y - p.y};
    }
    double operator*(Point p) const
    {
        return x * p.x + y * p.y;
    }
    double operator^(Point p) const
    {
        return x * p.y - y * p.x;
    }
};

double distance(Point A, Point B, Point C)
{
    Point AB = B - A;
    Point BC = C - B;
    Point AC = C - A;

    double AB_BC = (AB * BC);
    double AB_AC = (AB * AC);

    if (AB_BC > 0)
        return (C - B).len();
    else if (AB_AC < 0)
        return (C - A).len();
    return abs((AB ^ AC) / (AB * AC));
}

int main()
{
    Point A, B, C;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cout << distance(A, B, C);

    return 0;
}