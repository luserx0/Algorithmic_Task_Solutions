#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
   long n,k;
   cin >> n;
   cin >> k;

   long no_of_moves = n / k;

   if( no_of_moves % 2 == 1 )
      printf("YES\n");
   else
      printf("NO\n");

   return 0;
}
