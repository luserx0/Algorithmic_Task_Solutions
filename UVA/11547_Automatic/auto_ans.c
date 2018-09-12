#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calc(int a)
{
   a = (a * 567 / 9 + 7492) *235/47 - 498;
   return abs((a%100)/10);
}

int main(){
   
   int t, i;

   scanf("%d",&t);

   for (i = 0; i < t; ++i){
      int n;
      scanf("%d", &n);
      printf("%d\n", calc(n));
   }

   exit(0);
}
