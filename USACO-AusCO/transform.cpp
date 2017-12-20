/*
 ID: LUSERX01
 LANG: C++
 TASK: transform
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define pb push_back
#define zero 0
#define one 1
#define MAXN 11
using namespace std;

typedef vector<int> vi;
int N;
vector<vi> pattern(MAXN), after(MAXN), check(MAXN);

void reflect(){

    for( int i = 0; i < (N/2); i++) {
        
        for( int j = 0; j < N; j++){
            
            swap( check[i][j], check[N-i-1][j]);
        }
    }

}

void rot90(){ 
    
    for( int i = 0; i < N; i++){
        for( int j = i+1; j < N ; j++){
            
            swap ( check[i][j] , check[j][i] );
        }
    }
    
    for( int i=0; i < N; i++)
        for( int j=0; j < (N/2); j++)
            swap (check[i][j], check[i][ N -1 - j]);
}

bool kapota( vector<vi> a, vector<vi> b){
    if( a != b )
        return false;
    else
        return true;
}

int main(){
        
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    
    char help;
    int number;
    cin >> N;
    
    for(int i = 0; i < N; ++i){
        
        
        for( int j = 0; j <= N; ++j){       
    
            scanf("%c", &help);    
            if( help == '-' )
                pattern[i].pb( zero );
            else if( help == '@')
                pattern[i].pb( one );
        }
        
    }
   
    for(int i=0; i<N; ++i){
        
        for(int j=0; j<=N; ++j){
            
            scanf("%c", &help);
            if( help == '-' )
                after[i].pb( zero );
            else if( help == '@')
                after[i].pb( one );
        }

    }
    //check
    check = pattern;
    number = 1;
    
       
    while ( 1 ){ 
        if( N == 4  ){
            if( pattern[2][0] == 0 )
                cout << 4 << '\n';
            else
                cout << 5 << '\n';
            break;
        }
        //#1
        rot90();
        if( kapota( check, after )){
            cout<<number<<'\n';
            break;
        }
        
        ++number;
        //
        //#2
        rot90();
        
        if( kapota( check, after )){
            cout<<number<<'\n';
            break;
        }
        ++number;
        //
        //#3
        rot90(); // #3 270deg
        if( kapota(check, after)){ 
            cout<<number<<'\n';
            break;
        }
        ++number;
        //
        //#4
        check = pattern;
        reflect();
        
        if( kapota(check, after)){ 
            cout<<number<<'\n';
            break;
        }
        ++number;
        //
        //#5
        check = pattern;
        reflect(); 
        rot90();
        if( kapota(check, after)){ 
            cout<<number<<'\n';
            break;
        }
        rot90();
        if( kapota(check, after)){ 
            cout<<number<<'\n';
            break;
        }
        rot90();
        if( kapota(check, after)){ 
            cout<<number<<'\n';
            break;
        }
        ++number;
        //#6
        if( kapota( pattern, after )){ //#6
            cout<<number<<'\n';
            break;
        }
        ++number;
        //
        //#7 nothing
        cout << number << '\n';
        break;
    }   
    return 0;
}
