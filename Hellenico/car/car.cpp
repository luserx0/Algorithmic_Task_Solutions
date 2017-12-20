#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define MAXN 100008

typedef vector<int> vi;
//typedef vector<vi> vvi;
vi nodes[ MAXN ];

int find_depth( int node, int DpthCnt ){
    
    int size = nodes[ node ].size(); //ok
    
    cout << "Depth: " << DpthCnt << " Node: " << node <<'\n';

    for( int i = 0; i < size; ++i ){ //here lies a problem  == OK
        
        if( i == 0 )
           DpthCnt++;
        DpthCnt = find_depth( nodes[node][ i ], DpthCnt );
    
    }
    
    
    return DpthCnt;
}

int main(){
    
    //freopen("rentacar.in","r",stdin);
    //freopen("rentacar.out","w",stdout);
    
    int N, max_to = 0, max_count = 0, countD;
    
    scanf("%d", &N);

    for( int i = 0; i < N; ++i){

        int O, from, to;

        scanf("%d %d %d", &O, &from, &to );
        
        nodes[ from ].push_back( to+1 );
        
        if( to > max_to )
            max_to = to;
    }    
   
    //cout << "hi\n"; 
    
    for( int i = 0; i < max_to; ++i ){
        
        countD = 0;
        countD = find_depth( i, 0 );
        
        //cout << countD << " i=" << i << '\n';

        if( countD > max_count )
            max_count = countD;
    }
    
    printf("%d\n", max_count);
    return 0;
}
