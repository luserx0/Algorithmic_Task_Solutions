#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define pb push_back

struct elem{

   int start;
   int end;
   int number;
};


bool compr1( elem a, elem b ){
    
    return a.start < b.start;
}

bool compr2( elem a, elem b ){
    
    return a.end < b.end;
}

int main(){
 
    freopen("rentacar.in","r",stdin);
    
    int n, max = 0;
    vector<elem> starts; //not only for starts but global
    
    cin >> n;
    for( int i=0; i < n; ++i ){
        
        elem help;
        cin >> help.number >> help.start >> help.end;
        
        starts.pb( help );

        if( help.end > max )
           max = help.end;

    }
    
    sort( starts.begin(), starts.end(), compr1 );
    
    for( int i=0; i < n; ++i ){

        if( starts[i].start == starts[i+1].start )
            
            if( starts[i].end < starts[i+1].end )
                
                starts.erase( starts.begin() + i+1 );
                n--;
    }
    
    sort( starts.begin(), starts.end(), compr2 );

    for( int i=0; i < n; ++i ){

        while( starts[i].end == starts[i+1].end )
            
            if( starts[i].start > starts[i+1].start ){
                
                starts.erase( starts.begin() + i+1 );
                n--;
            }
    }
       
    return 0;
}
