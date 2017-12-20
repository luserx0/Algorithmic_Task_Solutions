/*
 ID: luserx01
 TASK: milk
 LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAXM 5008

using namespace std;

struct farmer{
    
    int price;
    long milk;
};

bool compre( farmer a, farmer b ){
    
    return ( a.price < b.price );
}

int main(){
    
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    
    int M, i;
    long N, result=0;

    scanf("%ld %d", &N, &M);
    
    farmer MMM[ MAXM ] = {0};
    
    for( i = 0; i < M; ++i ){
        
        int p;
        long m;
        farmer x;
        
        scanf("%d %ld", &p, &m );
        
        x.price = p;
        x.milk = m;
        MMM[ i ] = x;
    }
    
    if( M != 0 )
        sort( MMM, MMM + M , compre);
    //printf( "%d", MMM[0].price );

    i = 0;
    while( N - MMM[ i ].milk > 0 ){
        
        result += MMM[i].milk * MMM[i].price;
        N -= MMM[i].milk;
        ++i;
    
    }
    
    result += MMM[i].price * N;
    
    printf("%ld\n", result);

    return 0;
}
