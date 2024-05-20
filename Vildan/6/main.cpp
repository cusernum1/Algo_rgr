#include <iostream>
#include <utility>
#include <cstdlib>

using namespace std; 

template <typename T>
class ITreap
{
    struct node
    {
        int x;
        T v;
        int y;
        node *left = nullptr, *right = nullptr;
        node(int x, T v, int y) : x(x), v(v), y(y) {}
        void update() { x = 1 + (left ? left->x : 0) + (right ? right->x : 0); }
    };
    node *root;
    pair<node *, node *> split(node *t, int k)
    {
        if (!t)
            return {nullptr, nullptr};
        if (k == 0)
            return {nullptr, t};
        int l = (t->left ? t->left->x : 0);
        if (l < k)
        {
            auto [t1, t2] = split(t->right, k - l - 1);
            t->right = t1;
            t->update();
            return {t, t2};
        }
        else
        {
            auto [t1, t2] = split(t->left, k);
            t->left = t2;
            t->update();
            return {t1, t};
        }
    }
    node *merge(node *t1, node *t2)
    {
        if (!t2)
            return t1;
        if (!t1)
            return t2;
        if (t1->y > t2->y)
        {
            t1->right = merge(t1->right, t2);
            t1->update();
            return t1;
        }
        else
        {
            t2->left = merge(t1, t2->left);
            t2->update();
            return t2;
        }
    }
    void free(node *t)
    {
        if (!t)
            return;
        free(t->left);
        free(t->right);
        delete t;
    }
    node *find(int k)
    {
        node *p = root;
        while (p)
        {
            int l = (p->left ? p->left->x : 0);
            if (l == k)
                break;
            else if (k < l)
                p = p->left;
            else
            {
                k -= l + 1;
                p = p->right;
            }
        }
        return p;
    }
    void foreach (void (*f)(T x), node * p)
    {
        if (!p)
            return;
        foreach (f, p->left);
        f(p->left, p->right);
        foreach (f, p->right);
    }

public:
    ITreap() {}
    ~ITreap() { free(root); }
    int size() { return root ? root->x : 0; }
    T &operator[](int k)
    {
        if (k < 0 || k >= size())
            throw runtime_error("Wrong index");
        node *p = find(k);
        return p->v;
    }
    T operator[](int k) const
    {
        if (k < 0 || k >= size())
            throw runtime_error("Wrong index");
        node *p = find(k);
        return p->v;
    }
    void insert(int k, T v)
    {
        if (k < 0 || k > size())
            throw runtime_error("Wrong index");
        node *m = new node(1, v, rand());
        auto [t1, t2] = split(root, k);
        root = merge(merge(t1, m), t2);
    }
    void erase(int k)
    {
        if (k < 0 || k >= size())
            throw runtime_error("Wrong index");
        auto [t1, t] = split(root, k);
        auto [m, t2] = split(t, 1);
        root = merge(t1, t2);
        free(m);
    }
    void foreach (void (*f)(T x))
    {
        foreach (f, root);
    }
};

int main()
{
    ITreap<int> tree;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        tree.insert(i, k);
    }

    return 0;
}