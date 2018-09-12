#include <cstdio>
#include <iomanip>
#include <set>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

set<string> datapool;
int N, M, K;

void create_Datapool(){
    
    if( K == 4 ){
        for( int i=1; i <= M; ++i){
            for( int j=1; j <= M; ++j){
                for( int k=1; k <= M; ++k){
                    for( int f=1; f <= M; ++f){
                    
                        string bingo;
                        char c;
                        c = '0' + i;
                        bingo += c;
                        c = '0' + j;
                        bingo += c;
                        c = '0' + k;
                        bingo += c;
                        c = '0' + f;
                        bingo += c;
                        datapool.insert( bingo );
                    }
                }
            }
        }        
    }
    else if ( K == 3 ){
            for( int j=1; j <= M; ++j){
                for( int k=1; k <= M; ++k){
                    for( int f=1; f <= M; ++f){
                    
                        string bingo;
                        char c;
                        c = '0' + j;
                        bingo += c;
                        c = '0' + k;
                        bingo += c;
                        c = '0' + f;
                        bingo += c;
                        datapool.insert( bingo );
                    }
                }
            }
    }
    
    else if ( K == 5 ){
            for( int i=1; i <= M; ++i){
                for( int j=1; j <= M; ++j){
                    for( int k=1; k <= M; ++k){
                        for( int f=1; f <= M; ++f){
                            for( int w=1; w <= M; ++w){
                                string bingo;
                                char c;
                                c = '0' + i;
                                bingo += c;
                                c = '0' + j;
                                bingo += c;
                                c = '0' + k;
                                bingo += c;
                                c = '0' + f;
                                bingo += c;
                                c = '0' + w;
                                bingo += c;
                                datapool.insert( bingo );
                            }
                        }
                    }
                }
            }        
    }

}

void Check( string wanted, int ts, int fs ){

    //xeroume ts, fs
    set<char>wd;
    for(int k=0; k < K; ++k)
        wd.insert( wanted[ k ] );
    set<string> :: iterator it;

    for( it = datapool.begin(); it != datapool.end(); ){
        
        //ts' condition
        int counts = 0;
        string current = *it;
        
        for( int i=0; i<K; ++i){
            if( current[i] == wanted[i] )
                ++counts;
        }
        
        if( counts != ts ){
            datapool.erase( it++ );
        }
        else
            ++it;
    }
    
    for( it =datapool.begin(); it != datapool.end(); ){
        
        //fs' condition
        int count = 0;
        string current = *it;

        set<char> please;
        for( int i=0; i <K; ++i){
            please.insert( current[ i ] );
        }
        
        set<char> :: iterator help,help2;
        for( help = please.begin(); help != please.end(); ++help ){
            
            char c = *help;
            for ( help2 = wd.begin(); help2 != wd.end(); ++help2){
                
                char s = *help2;
                if( c == s )
                    ++count;
            }
        }

        if( count == fs+ts )
            ++it;
        else
            datapool.erase( it++ );
    
    }
      
}

int main(){

    freopen("mastermind.in","r",stdin);
    freopen("mastermind.out","w",stdout);

    int ts, fs, result;
       
    scanf("%d %d %d", &N, &M, &K);
    
    create_Datapool();
    
    for( int j=0; j<N; ++j){
        string start;
        for( int i=0; i<K; ++i){
            char help;
            cin >> help;
            start += help;
        }
        cin >> ts;
        cin >> fs;
        Check( start, ts, fs);
        
    }
    
    set<string> :: iterator it;
    //for( it = datapool.begin(); it != datapool.end(); ++it)
        //cout << *it<< '\n';
    result = 0 + datapool.size();
    printf("%d\n", result);
    return 0;
}
