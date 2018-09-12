#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


#define pb push_back

int main(){

    long n;
    
    scanf("%ld", &n);

    while(  n!= 0 ){
        
        vector<int> ppl;

        for( int i=0; i<n; ++i ){
            
            int a;
            scanf("%d", &a);
            ppl.pb( a );

        }
        sort(ppl.begin(), ppl.end());

        for( int j=0; j < n; ++j ){
            
            if( j == n-1 )
                printf("%d\n", ppl[j]);
            else
                printf("%d ", ppl[j]);
        }
        
        scanf("%ld", &n);
    }
    return 0;
}
