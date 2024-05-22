#include <iostream>
#include <queue>

using namespace std;

void print(int N) 
{
   queue<int> m1;
   queue<int> m2;

   // Заполнение входной очереди числами от 2 до N
   for (int i = 2; i <= N; ++i) 
   {
      m1.push(i);
   }

   while (!m1.empty()) 
   {
      int x = m1.front();
      cout << x << " "; // Печать простого числа

      m1.pop();

      // Перенос не кратных числу X в выходную очередь
      while (!m1.empty()) 
      {
         int num = m1.front();
         m1.pop();

         if (num % x != 0) 
         {
            m2.push(num);
         }
      }

      // Обмен входной и выходной очередями
      swap(m1, m2);
   }
}

int main() 
{
   int N;
   cout << "Введите число N (2 <= N <= 100000): ";
   cin >> N;

   cout << "Простые числа от 2 до " << N << endl;
   print(N);

   return 0;
}