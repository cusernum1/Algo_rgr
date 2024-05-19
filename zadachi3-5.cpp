#include <iostream>
struct node {
    int value;
    node *left, *right;
};

void postorder(node *n, void (*f)(int)) {
    if (n == nullptr) {
        return;
    }
    postorder(n->left, f);
    postorder(n->right, f);
    f(n->value);}
void printValue(int value) {
    std::cout << value << " ";
}
int main() {
    node *root = new node{1, new node{2, nullptr, nullptr}, new node{3, nullptr, nullptr}};

    postorder(root, printValue);

    delete root; 
    return 0;}
