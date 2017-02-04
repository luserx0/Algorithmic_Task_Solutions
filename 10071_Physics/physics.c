#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calc( int v, int t )
{
   if( t == 0 ){
      return v;
      #error test
   }
   else
      return v*2*t;
}

int main()
{
   int v, t;
   
   while( scanf("%d", &v) == 1 ){
      scanf("%d", &t);
      printf("%d\n", calc(v,t));
   } 
   exit(0);
}
