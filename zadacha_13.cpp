#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Circle 
{
   double x, y, d;
};
bool areCirclesConnected(const Circle& c1, const Circle& c2) 
{
   double distance = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
   return distance <= (c1.d + c2.d) / 2;
}
void dfs(int v, const vector<vector<int>>& adj_list, vector<bool>& visited) 
{
   visited[v] = true;
   for (int u : adj_list[v]) 
   {
      if (!visited[u]) 
      {
         dfs(u, adj_list, visited);
      }
   }
}
int countConnectedComponents(const vector<Circle>& circles) 
{
   int n = circles.size();
   vector<bool> visited(n, false);
   vector<vector<int>> adj_list(n);
   for (int i = 0; i < n; ++i) 
   {
      for (int j = i + 1; j < n; ++j) 
      {
         if (areCirclesConnected(circles[i], circles[j])) 
         {
            adj_list[i].push_back(j);
            adj_list[j].push_back(i);
         }
      }
   }
   int count = 0;
   for (int i = 0; i < n; ++i) 
   {
      if (!visited[i]) 
      {
         dfs(i, adj_list, visited);
         count++;
      }
   }
   return count;
}

int main() 
{
   vector<Circle> circles = 
   {
      {0, 0, 2},
      {2, 0, 2},
      {-3, 2, 2},
      {1, 2, 2}
   };

   int numComponents = countConnectedComponents(circles);
   cout << "Число компонент связности: " << numComponents << endl; // Вывод: 2

   return 0;
}