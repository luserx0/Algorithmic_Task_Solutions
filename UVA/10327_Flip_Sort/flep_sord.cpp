#include <cstdio>
#include <algorithm>

#define swap(x,y,t) do { t swap = x; x=y; y=swap; } while(0)

long flip_sort( long array[], long N )
{
   long i, counter = 0;
   bool swapped;

   do
   {
      swapped = false;
      for (i = 0; i < N-1; ++i)
      {
         if( array[i] > array[i+1] )
         {
            swap(array[i], array[i+1], long);
            swapped = true;
         counter++;
         }
      }
   } while (swapped);

   return counter;
}

int main()
{
   long N, i;
   
   while( scanf("%ld", &N ) == 1 )
   {
      long array[N];
      for (i = 0; i < N; ++i)
      {
         scanf("%ld", &array[i]);
      }
      
         printf("Minimum exchange operations : %ld\n", flip_sort( array, N));

   }
   return 0;
}
