/*
ID: LUSERX01
LANG: C++
TASK: beads

*/
#include <cstdio>
#include <string>
#include <iostream>
#include <set>

using namespace std;

int main(){
    
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    
    string start;
    int N, max=0;
    bool FLAG, first, second;
    
    cin >> N;
    
    cin >> start; 
    
    string help = start;
    help += start;
    
    for(int i=0; i < N; ++i){
        
    
        FLAG = true;
        first = true;
        second = false;

        int count = 0;
        int bead = i;
        char c = 'w';
        char w = 'w';
        
        while( FLAG && count < N ){
            
            char helpch = help[bead];   
            if( helpch != w ){
                
                if( first ){        //FIRST NONW
                    c = help[bead];
                    first = false;
                }    
                else if (helpch != c){
                    
                    if( !second ){
                        c = help[ bead ];
                        second = true;
                    }
                       
                    else{
                        FLAG = false;
                        //cout << help[bead] << endl;
                    }
                }
            }    
            
            if( FLAG ){
                ++count;
                ++bead;
            }
            if( count > max )
                max = count;
             
        }
    
    }
    printf("%d\n", max);

    return 0;
}
