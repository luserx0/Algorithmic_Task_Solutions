#include "stdio.h"
#include "string.h"

#define MAXN 2000005
#define MAX(x, y) (((x) > (y)) ? (x) : (y))


int main(){
    
    FILE *in = fopen("scrabble1d.in","r"),
         *out = fopen("scrabble1d.out","w");
            
    long arr[ MAXN ], aux[ MAXN ], n, k, i, j, big1=0, big2=0, Big, indexB1;
    
    memset( arr, 0, MAXN );
    memset( aux, 0, MAXN );

    fscanf(in, "%ld %ld", &n, &k );

    for( i=1; i <= n; ++i )
        fscanf(in, "%ld", &arr[ i ] );
     
    for( j = 1; j <= k; ++j )
        aux[ 1 ] += arr[ j ];
    
    for( i = 2; i <= n - k/2; ++i ){
        aux[i] = aux[i-1] + arr[i+k-1] - arr[i-1];
    }// initialize aux

    long kurwa=0, K2;
    for( i = 1; i <= 2*k; ++i ){
        kurwa += arr[ i ];
    }
    
    K2 = kurwa;
    
    for ( j=2; j <= n - 2*k + 1; ++j) {
        kurwa = kurwa + arr[j + 2*k - 1] - arr[j-1];
        K2 = MAX( K2, kurwa);
    }//count biggest continuous sum
            
    for( i=1; i <= n-k; ++i ){
        
        if( aux[ i ] > big1 ){
                
            big1 = aux[i];
            indexB1 = i;
        }
    }
            
    for( i = indexB1; i < indexB1+k; ++i ) 
        aux[ i ] = 0;
    for( i = indexB1; i > indexB1-k; --i )
        aux[ i ] = 0; 
    
    big2 = 0;
    for( i = 1; i <= n; ++i ){
        big2 = MAX( big2, aux[ i ] );
    }
    
    Big = big1 + big2;
    if( Big < K2 )
        Big = K2;

    fprintf(out,"%ld\n", Big );
   
    return 0;
}
