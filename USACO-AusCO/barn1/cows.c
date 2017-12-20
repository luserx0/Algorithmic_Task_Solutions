/*
 ID: luserx01
 LANG: C
 TASK: barn1
*/
#include "stdio.h"
#include "string.h"

#define MAXS 201

int main(){
   
   freopen("barn1.in","r",stdin);
   freopen("barn1.out","w",stdout);

   int N, C, S, stalls[MAXS] = {0}, i, j, result, first=-1, last=-1;
   int max = 0;
   int min = MAXS;

   scanf("%d %d %d", &N, &S, &C);
   
   for (i = 0; i < C; ++i)
   {
      int help;
      scanf("%d", &help);
      
      stalls[help] = 1;

      if( min > help ) min = help;
      if( max < help ) max = help;

   }
   first = min;
   last = max;

   result = last - first + 1; // N=1 Init
   
   for (i = 1; i < N; ++i)
   {
      int maxL = 0, maxS=-1, maxE=-1;
      for (j = first+1; j < last; ++j)
      {
         if( stalls[j] == 0 )
         {
            int start = j, end = j;
            ++j;
            while( stalls[j] == 0 )
            {
               ++end;
               ++j;
            }
            int length = end - start + 1;
            if( length > maxL )
            {
               maxL = length;
               maxS = start;
               maxE = end;
            }
         }
      }
      for (j = maxS; j <= maxE; ++j)
      {
         stalls[j] = -1;
      }
      result -= maxL;
   }
   
   printf("%d\n", result); 
   
   return 0;
}

