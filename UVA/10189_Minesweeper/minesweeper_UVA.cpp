#include "stdio.h"
#include "stdlib.h"
#include <iostream>

#define PRINT printf("\n Status OK\n");
/*Removed all of my comments due to compiler ansi C error ;-(*/
using namespace std;

int main()
{
   long M, N, testcase_count=0;
   
   scanf("%ld %ld", &N, &M);
   while( M != 0 || N != 0)
   {
      testcase_count++; 
      if( testcase_count > 1 )
         printf("\n");
      
      long table[N+2][M+2];
      long i, j, k, l, cnt;

      for (i = 0; i <= N+1; ++i){
         for (j = 0; j <= M+1; ++j){
            table[i][j] = 0;
         } 
      } 

      for (i = 1; i <= N; ++i) 
      {
         for (j = 1; j <= M; ++j)
         {
            char bomb42;
            cin >> bomb42;
               if( bomb42 == '*' ){
                  table[i][j] = 42;
               }
         }
      } 
      

      for (i = 1; i <= N; ++i)
      {
         for (j = 1; j <= M; ++j)
         {
            if( table[i][j] != '*')
            {
               cnt = 0;
               for (k = i-1; k <= i+1; ++k)
               {
                  for (l = j-1; l <= j+1; ++l)
                  {   
                     if( table[k][l] == '*' )
                        cnt++;
                     //printf("table[k][l]:%ld \t cnt:%ld \n", table[k][l], cnt);
                  }
               } 
               table[i][j] = cnt;
            }
         }  
      }
      
      printf("Field #%ld:\n", testcase_count);
      for (i = 1; i <= N; ++i)
      {
         for (j = 1; j <= M; ++j)
         {
            if( table[i][j] == 42 )   
               printf("*");
            else
               printf("%ld", table[i][j]);
         } 
         printf("\n");
      } 
      
      scanf("%ld %ld", &N, &M);
   }
   return 0;
}
