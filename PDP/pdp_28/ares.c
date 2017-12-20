/*
 *
 * Intellectual Property of 
 * Konstantinos Angelopoulos
 *
 * ------------------
 * |                |
 * |    RESPECT     |
 * |                |
 * ------------------
*/
#define ll long long
#include "stdio.h"
#include "string.h"


int main()
{
     long n, m, ari8mos, big=0, small=10000000, Somades=0, A[1000001];
     
    
    FILE *in = fopen("aris.in","r"),
         *out = fopen("aris.out","w");
    
    fscanf( in ,"%d %d", &n, &m );
        
    memset(A, 0 ,sizeof(A));
    
    for(ari8mos=1; ari8mos <= n; ++ari8mos )
    {   
            ll input;
            fscanf(in, "%d", &input);
            ++A[ input ];
    }
    
    for(ari8mos=1; ari8mos <= m; ++ari8mos)
    {
        if(A[ari8mos] != 0)
        {
            ++Somades;
            
            if(A[ari8mos] > big)
                big = A[ari8mos];
                    
            if(A[ari8mos] < small)
                small = A[ari8mos];
        }
    }
    
    fprintf( out, "%d %d %d\n", Somades, small, big);

    return 0;
}
    
    
