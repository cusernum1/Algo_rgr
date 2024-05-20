struct node
{
    int value;
    node *left, *right;
};

void inorder(node *n, void (*f)(int))
{
    if (!n)
        return;
    inorder(n->left, f);
    f(n->value);
    inorder(n->right, f);
}