#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <iostream>

using namespace std;

#define MAXN 1008

int N, C, X; 
vector <string> cases;
set <string> possiblus;
set <string> :: iterator it;

string switch1(string lights){
    
    
    for(int i=0; i<N; ++i){
        
        if( lights[i] == '1' )
            lights[i] = '0';
        else
            lights[i] = '1';
    }
    return lights;
}

string switch2(string lights){
    
    
    
    for( int i=0; i<N; i+=2){
        
        if( lights[i] == '1' )
            lights[i] = '0';
        else
            lights[i] = '1';       
    }
    
    return lights;

}

string switch3(string lights){

    for ( int i=1; i<N; i+=2){
        
        if( lights[i] == '1')
            lights[i] = '0';
        else
            lights[i] = '1';
    }   
    
    return lights;
}

string switch4(string lights){

    for ( int i=0; i<N; i+=3 ){
        if(lights[i] == '1')
            lights[i] = '0';
        else
            lights[i] = '1';
    }
    
    return lights;
}
string caserino(string binCS){
    
    string result;
    result.assign( N, '1');
    if( binCS[0] == '1'){
        result = switch1(result);
    }
    //cout << result << " " << binCS << endl;

    if( binCS[1] == '1'){
        result = switch2(result);
    }
    //cout << result << " " << binCS << endl;
    if( binCS[2] == '1'){
        result = switch3(result);
    }
    //cout << result << " " << binCS << endl;
    
    if( binCS[3] == '1'){
        result = switch4(result);
    }
    //cout << result << " " << binCS << endl;
    return result;
}

void Comp(){
    for(int i=0; i < 16; ++i){ //pithanoi syndyasmoi diakoptwn arithmimenoi se 10diko
      
        bitset <4> x(i);
        string help = x.to_string();
        cases.push_back(help);
        
    }
    
    //here starts the problem
    
    string help, computed;
    
    if (C == 1){
        int ones[] = {1,2,4,8};
        for(int i=0; i < 4; ++i){ 
            
            help = cases[ ones[i] ];
            
            computed = caserino(help);                
            possiblus.insert(computed);
        }           
    
    }
    else if(C == 2){
        int twos[] = {3,6,9,12,10,5,0};
        
        for(int i=0; i < 7; ++i){ 
            
            help = cases[ twos[i] ];
            
            computed = caserino(help);                
            possiblus.insert(computed);
        }
    }
    else{
        if( C % 2 ==  0){
                   
            int two[] = {3,6,9,12,10,5,0,15};
            for(int i=0; i < 8; ++i){ 
            
                help = cases[ two[i] ];
            
                computed = caserino(help);                
                possiblus.insert(computed);
            }           
        }
        else{
        
            int ones[] = {1,2,4,8,7,11,13,14};
            for( int i=0; i < 8; ++i){
            
                help = cases[ ones[i] ];
                
                computed = caserino(help);
                possiblus.insert(computed);
            }   
        }
    }
}

void Delete1(int H){
    
    string help;
    for(it = possiblus.begin(); it != possiblus.end(); ++it){
        
        help = *it;
        if( help[ H-1 ] != '1' )
            possiblus.erase( *it );
    }
}

void Delete0(int H){
 
    string help;
    //set <string> :: iterator it;
    for(it = possiblus.begin(); it != possiblus.end(); ++it){
        
        help = *it;
        if( help[ H-1 ] != '0' )
            possiblus.erase( *it );
    }
}
void Solve(){

    scanf("%d", &X);
    while( X != -1){
        
        Delete1(X);
        scanf("%d", &X);
    }
    
    scanf("%d", &X);
    while( X != -1){
    
        Delete0(X);
        scanf("%d", &X);
    }
}

int main(){
    
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);

    scanf("%d", &N);
    scanf("%d", &C);
    
    Comp(); 
    //printf("HELLO"); 
    Solve();
        
    //sort(possiblus.begin(), possiblus.end());
      
    for ( it = possiblus.begin(); it != possiblus.end(); ++it ){
        
       cout << *it << endl;        
    }
    return 0;
}
