vector<int> primeFactorization(int num) 
{
   vector<int> factors;
   if (num <= 1) 
   {
      return factors; 
   }
   while (num % 2 == 0)
   {
      factors.push_back(2);
      num /= 2;
   }
   for (int i = 3; i * i <= num; i += 2) 
   {
      while (num % i == 0) 
      {
         factors.push_back(i);
         num /= i;
      }
   }
   if (num > 1) 
   {
      factors.push_back(num);
   }
   return factors;
}
