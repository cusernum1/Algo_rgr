#include <functional>

using namespace std;

struct node {
    int value;
    node *left;
    node *right;
};

void preorder(node *n, function<void(int)> f) {
    if (n == nullptr) {
        return;
    }
    f(n->value);
    preorder(n->left, f);
    preorder(n->right, f);
}
