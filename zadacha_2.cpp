#include <iostream>
#include <queue>

using namespace std;

void print(int N) 
{
   queue<int> m1;
   queue<int> m2;

   // ���������� ������� ������� ������� �� 2 �� N
   for (int i = 2; i <= N; ++i) 
   {
      m1.push(i);
   }

   while (!m1.empty()) 
   {
      int x = m1.front();
      cout << x << " "; // ������ �������� �����

      m1.pop();

      // ������� �� ������� ����� X � �������� �������
      while (!m1.empty()) 
      {
         int num = m1.front();
         m1.pop();

         if (num % x != 0) 
         {
            m2.push(num);
         }
      }

      // ����� ������� � �������� ���������
      swap(m1, m2);
   }
}

int main() 
{
   int N;
   cout << "������� ����� N (2 <= N <= 100000): ";
   cin >> N;

   cout << "������� ����� �� 2 �� " << N << endl;
   print(N);

   return 0;
}