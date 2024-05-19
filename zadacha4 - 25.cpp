#include <iostream>
#include <vector>
using namespace std;

vector<int> toPrimeDivisors(int number)
{
   vector<int> ans;
   for (int i = 2; i * i <= number; i++)
   {
      while (number % i == 0)
      {
         number /= i;
         ans.push_back(i);
      }
      if(number != 1)
         ans.push_back(number);
   }
   return ans;
}
int main()
{
   return 0;
}