#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Queue
{
    size_t max_sz, sz, fr, back;
    vector<T> q;

public:
    Queue() : max_sz(2), sz(0), q(2), fr(0), back(0) {}
    void push(T el);
    void pop();
    T front();
    size_t size() const { return sz; }
};

template <typename T>
void Queue<T>::push(T el)
{
    if (sz == max_sz)
    {
        max_sz *= 2;
        q.resize(max_sz);
        if (fr != 0)
        {
            for (int i = fr; i < sz; i++)
                q[sz + i] = q[i];
            fr += sz;
        }
    }

    if (back >= max_sz)
        back = 0;

    q[back++] = el;
    sz++;
}

template <typename T>
void Queue<T>::pop()
{
    if (sz == 0)
        return;

    fr++;
    if (fr >= max_sz)
        fr = 0;

    sz--;
}

template <typename T>
T Queue<T>::front()
{
    return q[fr];
}

int main()
{
    Queue<int> q;
    for (int i = 1; i <= 40; i++)
    {
        for (int j = 1; j <= i; j++)
            q.push(j);
        while (q.size())
        {
            cout << q.front() << ' ';
            q.pop();
        }
        cout << '\n';
    }

    return 0;
}