#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Cell 
{
   int row, col, time;
};
bool isValid(int row, int col, int N, int M) 
{
   return row >= 0 && row < N && col >= 0 && col < M;
}
int main() 
{
   int N, M;
   cin >> N >> M;
   vector<vector<char>> map(N, vector<char>(M));
   queue<Cell> q;
   for (int i = 0; i < N; ++i) 
   {
      for (int j = 0; j < M; ++j) 
      {
         cin >> map[i][j];
         if (map[i][j] == '*') 
         {
            q.push({i, j, 0});
         }
      }
   }
   int maxTime = 0;
   while (!q.empty()) 
   {
      Cell curr = q.front();
      q.pop();
      maxTime = max(maxTime, curr.time);
      int dr[] = {-1, 1, 0, 0};
      int dc[] = {0, 0, -1, 1};
      for (int i = 0; i < 4; ++i) 
      {
         int newRow = curr.row + dr[i];
         int newCol = curr.col + dc[i];
         if (isValid(newRow, newCol, N, M) && map[newRow][newCol] == '.') 
         {
            map[newRow][newCol] = '#'; 
            q.push({newRow, newCol, curr.time + 1});
         }
      }
   }
   cout << maxTime << endl;
   return 0;
}