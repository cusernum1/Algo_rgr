N	        Время set	        Время unordered_set
100	        69200	        39000
10000	143600	        49100
10^6	        1262300	        206400
10^7	        1877000	        258200


#include <iostream>
#include <set>
#include <unordered_set>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;
int main() 
{
   int N;
   cout << "N: ";
   cin >> N;
   random_device rd;
   mt19937 gen(rd());
   uniform_int_distribution<> dist(1, 1000000000);
   set<int> Set;
   for (int i = 0; i < N; ++i) 
   {
      Set.insert(dist(gen));
   }
   unordered_set<int> UnorderedSet;
   for (int i = 0; i < N; ++i) 
   {
      UnorderedSet.insert(dist(gen));
   }
   auto startSet = high_resolution_clock::now();
   for (int i = 0; i < 1000; ++i) 
   {
      Set.find(dist(gen));
   }
   auto endSet = high_resolution_clock::now();
   auto startUnorderedSet = high_resolution_clock::now();
   for (int i = 0; i < 1000; ++i) 
   {
      UnorderedSet.find(dist(gen));
   }
   auto endUnorderedSet = high_resolution_clock::now();
   auto timeSet = duration_cast<nanoseconds>(endSet - startSet).count();
   auto timeUnorderedSet = duration_cast<nanoseconds>(endUnorderedSet - startUnorderedSet).count();
   cout << "set: " << timeSet << " ns" << endl;
   cout << "unordered_set: " << timeUnorderedSet  << " ns" << endl;
   return 0;
}