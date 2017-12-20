#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

structs nums{
   int n;
   int save = 1;
}

bool hello( nums a, nums b )
{
   return (a.n < b.n);
}


int main()
{
   long n, ones, twos, threes, twos_num = 0, threes_num = 0, i ,j, answer = 0;
   vector<nums> passed_nums;
   
   ones = twos = threes = 0;
   cin >> n; 
   
   for (i = 0; i < n; ++i)
   {
      long a;
      cin >> a;

      if(a==1)
         ones++;
      else if( a % 2 == 0){
         twos++;
         twos_num++;
      }
      else if( a % 3 == 0){
         threes++;
         threes_num++;
      }
      else
      {
         nums b;
         b.n = a;
         passed_nums.push_back(b);
         
      }
   }
    

   passed_nums.sort(passed_nums.begin(), passed_nums.end(), hello);
   
   for (i = 0; i < passed_nums.size() / 2; ++i)
   {
      for( j = i + 1; j < passed_nums.size(); ++j)
      {
         if( passed_nums[j].n % passed_nums[i].n == 0 )
         {
            passed_nums[i].save++;
         }
      }
      if( passed_nums[i].save > answer )
         answer = passed_nums[i].save
   }
