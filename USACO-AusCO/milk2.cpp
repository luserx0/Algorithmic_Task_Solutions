/*
ID: LUSERX01
LANG: C++
TASK: milk2
*/
#include<cstdio>  
#include<algorithm>  
#include<iostream>  
    
using namespace std;  
      
#define MAXN 1000008  
      
int main(){  
         
    freopen("milk2.in","r",stdin);  
    freopen("milk2.out","w",stdout);  

    long lc_max, lc_min, N, maxY=0, minY=0, max0=0, help=0;  
    long time[MAXN] = {0};  
        
    lc_max = 0;
    lc_min = MAXN;
          
    for(cin >> N; N; --N){  
              
        long A,B;  
        scanf("%ld %ld", &A, &B);  
            
        ++time[A];
        --time[B];

        if ( A < lc_min )
            lc_min = A;

        if ( B > lc_max )
            lc_max = B;
    }  
   
    long sequence = 1;
    
    for ( long i = lc_min; i <= lc_max; ++i){

        if ( help + time[ i ] > time [ i ] ){
            help += time[i];
            sequence++;
        }
            
        else{
            help = time[i];
            sequence = 0;
        }

        maxY = max( sequence, maxY ); 
        
        if (  help == 0 && i < lc_max ){
            minY++;
        }
        else{
            minY = 0;
        }
        
        max0 = max( minY, max0);
    }

    printf("%d %d\n", maxY, max0);  
    
          
    return 0;  
}  


