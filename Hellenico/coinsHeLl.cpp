#include <cstdio>

using namespace std;

char win[1000008];
int in[51];


int main(){
    
    freopen("coins.in","r",stdin);
    freopen("coins.out","w",stdout);
    
    int K, L, m, maxIN=0;
    int kd, ld, help, i;
    scanf("%d %d %d", &K, &L, &m);

    for( i=1; i<=m; ++i){
        
        scanf( "%d", &in[i] );
        if( in[i] > maxIN )
            maxIN = in[i];
    }
    
    win[0] = 0;
    for( i=1; i <= maxIN; ++i){
        
        help = win[i-1];
        if( i - K >= 0)
            kd = win[i-K];
        else
            kd = 1;

        if( i - L >= 0)
            ld = win[i-L];
        else
            ld = 1;

        if( help && kd && ld )
            win[i] = 0;
        else
            win[i] = 1;
    }

    for( i = 1; i <= m; ++i){
        if( win[ in[ i ] ] )
            printf("A");
        else
            printf("B");
    }
    printf("\n");
   
    return 0;
}
