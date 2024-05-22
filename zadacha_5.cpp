struct node 
{
   int value;
   node *left;
   node *right;
};
void preorder(node *n, void (*f)(int))
{
   if(n != nullptr) return;
   f(n->value);
   preorder(n->left, f);
   preorder(n->right, f);
}