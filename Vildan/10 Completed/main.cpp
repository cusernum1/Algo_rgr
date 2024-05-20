#include <iostream>
#include <vector>

using namespace std;

class Polynom
{
    vector<long double> coefs;

public:
    Polynom();
    Polynom(vector<long double> coefs) : coefs(coefs){};
    long double calc(long double x);
    Polynom operator+(Polynom b);
    Polynom operator*(Polynom b);
};

long double Polynom::calc(long double x)
{
    long double c = 1, ans = 0;
    for (int i = coefs.size() - 1; i >= 0; i--)
    {
        ans += c * coefs[i];
        c *= x;
    }

    return ans;
}

Polynom Polynom::operator+(Polynom b)
{
    vector<long double> c = coefs;
    if (b.coefs.size() > c.size())
        c.resize(b.coefs.size());
    for (int i = 0; i < b.coefs.size(); i++)
        c[i] += b.coefs[i];
    return Polynom(c);
}

Polynom Polynom::operator*(Polynom b)
{
    vector<long double> c(coefs.size() + b.coefs.size() - 1);
    for (int i = 0; i < coefs.size(); i++)
        for (int j = 0; j < b.coefs.size(); j++)
            c[i + j] += coefs[i] * b.coefs[j];
    return Polynom(c);
}