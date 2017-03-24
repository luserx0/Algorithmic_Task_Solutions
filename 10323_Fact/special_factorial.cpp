#include <iostream>
#include <cmath>
#include <cstdio>

#define ll long long

using namespace std;

int main()
{
   //freopen("input.in", "r", stdin);
   ll N;
   while( cin >> N )
   {
      if ( N > 0 )
      {
         if( tgamma(abs(N)+1 ) < 10000 )
            cout << "Underflow!" << '\n';
         else if( tgamma( abs(N+1)) > 6227020800 )
            cout << "Overflow!" << '\n';
         else
            cout << long(round(tgamma(abs(N)+1))) << '\n';
      }
      else
      {
         if( long(abs( N )) % 2 == 1)
            cout << "Overflow!" << '\n';
         else
            cout << "Underflow!" << '\n';
      }
   }
   return 0;
}
