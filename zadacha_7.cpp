#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

struct SegmentTree 
{
   int size;
   vector<long long> sums;
   vector<long long> multipliers;
   vector<long long> additions;
  
   void init(int n) 
   {
      size = 1;
      while (size < n) size *= 2;
      sums.assign(2 * size, 0);
      multipliers.assign(2 * size, 1);
      additions.assign(2 * size, 0);
   }
   
   void build(vector<long long> &a, int x, int lx, int rx) 
   {
      if (rx - lx == 1) 
      {
         if (lx < a.size()) 
         {
            sums[x] = a[lx];
         }
         return;
      }
      int m = (lx + rx) / 2;
      build(a, 2 * x + 1, lx, m);
      build(a, 2 * x + 2, m, rx);
      sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
   }

   void build(vector<long long> &a) 
   {
      init(a.size());
      build(a, 0, 0, size);
   }

   void add(int l, int r, long long v, int x, int lx, int rx) 
   {
      if (lx >= r || l >= rx) return;
      if (lx >= l && rx <= r) 
      {
         sums[x] += v * (rx - lx);
         sums[x] %= MOD;
         additions[x] += v;
         additions[x] %= MOD;
         return;
      }
      int m = (lx + rx) / 2;
      add(l, r, v, 2 * x + 1, lx, m);
      add(l, r, v, 2 * x + 2, m, rx);
   }

   void add(int l, int r, long long v) 
   {
      add(l, r, v, 0, 0, size);
   }

   void multiply(int l, int r, long long v, int x, int lx, int rx) 
   {
      if (lx >= r || l >= rx) return;
      if (lx >= l && rx <= r) 
      {
         sums[x] *= v;
         sums[x] %= MOD;
         multipliers[x] *= v;
         multipliers[x] %= MOD;
         additions[x] *= v;
         additions[x] %= MOD;
         return;
      }
      int m = (lx + rx) / 2;
      multiply(l, r, v, 2 * x + 1, lx, m);
      multiply(l, r, v, 2 * x + 2, m, rx);
   }

   void multiply(int l, int r, long long v) 
   {
      multiply(l, r, v, 0, 0, size);
   }

   long long get(int p, int x, int lx, int rx) 
   {
      if (rx - lx == 1) return sums[x];
      int m = (lx + rx) / 2;
      long long res;
      if (p < m) 
      {
         res = get(p, 2 * x + 1, lx, m);
      }
      else 
      {
         res = get(p, 2 * x + 2, m, rx);
      }
      res *= multipliers[x];
      res += additions[x] * (min(rx, p+1) - max(lx, p));
      res %= MOD;
      return res;
   }

   long long get(int p) 
   {
      return get(p, 0, 0, size);
   }
};

int main() 
{
   int n;
   cin >> n;
   vector<long long> a(n);
   for (int i = 0; i < n; i++) 
   {
      cin >> a[i];
   }
   
   SegmentTree st;
   st.build(a);
   
   int m;
   cin >> m;
   while (m--) 
   {
      int type;
      cin >> type;
      if (type == 1) 
      {
         int l, r;
         long long d;
         cin >> l >> r >> d;
         st.add(l-1, r, d);
      }
      else if (type == 2) 
      {
         int l, r;
         long long d;
         cin >> l >> r >> d;
         st.multiply(l-1, r, d);
      }
      else if (type == 3) 
      {
         int p;
         cin >> p;
         cout << st.get(p-1) << "\n";
      }
   }
   return 0;
}