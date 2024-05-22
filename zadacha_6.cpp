#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class ITreap 
{
   struct node 
   {
      T v; 
      size_t k; 
      int y; 
      node *left = nullptr, *right = nullptr;
      node(T v) : v(v), k(1), y(rand()) {}
      void update(ITreap<T>* treap) { k = 1 + treap->size(left) + treap->size(right); } 
   };
   node *root;
   size_t size(const node *n) const { return n ? n->k : 0; } 
   public:
      ITreap() : root(nullptr) {}
      ITreap(const ITreap&) = delete; 
      ITreap& operator=(const ITreap&) = delete; 
      ~ITreap() { free(root); }
      size_t size() const { return size(root); } 
      void insert(const T& v);
      node* insert(node* n, const T& v); 
      T kth(size_t k);
      node* kth(node* n, size_t k); 
     


      void free(node* n) 
      { 
         if (n) 
         {
            free(n->left);
            free(n->right);
            delete n;
         }
      }
};
template <typename T>
void ITreap<T>::insert(const T& v) 
{
   root = insert(root, v);
}
template <typename T>
ITreap<T>::node* ITreap<T>::insert(ITreap<T>::node* n, const T& v) 
{
   if (!n) return new node(v); 
   if (v < n->v) 
   {
      n->left = insert(n->left, v);
      n->update(this); 
   }
   else 
   {
      n->right = insert(n->right, v);
      n->update(this); 
   }
   return n;
}
template <typename T>
T ITreap<T>::kth(size_t k) { return kth(root, k)->v; }
template <typename T>
ITreap<T>::node* ITreap<T>::kth(ITreap<T>::node* n, size_t k) 
{
   if (!n) return nullptr;
   size_t lsize = size(n->left);
   if (lsize == k) return n;
   if (lsize > k) return kth(n->left, k);
   return kth(n->right, k - lsize - 1);
}
int main() 
{
   int n;
   cin >> n;
   ITreap<int> t;

   for (int i = 0; i < n; ++i) 
   {
      int a;
      cin >> a;
      t.insert(a);
      int centralIndex = (t.size() + 1) / 2;
      cout << t.kth(centralIndex - 1) << " ";
   }
   cout << endl;
   return 0;
}