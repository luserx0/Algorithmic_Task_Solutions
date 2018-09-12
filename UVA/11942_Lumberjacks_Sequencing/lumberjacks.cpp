#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int n, l;
    scanf("%d", &n);
    printf("Lumberjacks:\n");

    for(int i=0; i < n; ++i){
        
        bool FLAG = false;

        vector<int> lmbs;
        for( int j = 0; j < 10; ++j ){
            
            scanf("%d", &l);
            lmbs.push_back(l);

        }

        vector<int> lmbs2 = lmbs;
        sort(lmbs2.begin(), lmbs2.end() );
        
        if( lmbs == lmbs2 )
            FLAG = true;

        reverse( lmbs2.begin(), lmbs2.end() );

        if( lmbs == lmbs2 )
            FLAG = true;

        if( FLAG )
           printf("Ordered\n");
        else
           printf("Unordered\n");
    
    }


    return 0;
}
