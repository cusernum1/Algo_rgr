#include <iostream>
#include <set>

using namespace std;

int main()
{
   int n;      
   cin >> n;

   set<int> numbers;
   
   for (int i = 0; i < n; ++i)
   {
      int num;
      cin >> num;

      auto it = numbers.lower_bound(num);

      if (it != numbers.end()) 
      {
         cout << *prev(it) << " ";
      }
      else 
      {
         cout << "* ";
      }

      if (it != numbers.begin()) 
      {
         cout << *prev(it) << endl;
      } 
      else 
      {
         cout << "*\n";
      }

      numbers.insert(num);
   }

   return 0;
}