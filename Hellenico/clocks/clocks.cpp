/*
USER: luser
LANG: C++
TASK: clocks
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <iostream>

using namespace std;


bool custom( string a, string b){
    
    if( a.size() == b.size() )
        return a < b;
    else
        return (a.size() < b.size());
    
}

bool check( int a, int b, int c, int d, int e, int f, int g, int h, int i, vector<int> aux ){

    aux[0] = (aux[0] + a + b + d ) % 4;
    aux[1] = (aux[1] + a + b + c + e ) % 4;
    aux[2] = (aux[2] + c + b + f ) % 4;
    aux[3] = (aux[3] + a + d + e + g ) % 4;
    aux[4] = (aux[4] + a + c + e + g + i ) % 4;
    aux[5] = (aux[5] + c + e + f + i ) % 4;
    aux[6] = (aux[6] + d + g + h ) % 4;
    aux[7] = (aux[7] + e + g + h + i ) % 4;
    aux[8] = (aux[8] + f + h + i ) % 4;
    
    //cout << count ( aux.begin(), aux.end(), 0 ) << endl;
    
    if( count( aux.begin(), aux.end(), 0) == 9)
        return true;
    else
        return false;
    
}

int main(){
    
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
    
    vector <int> clocks;
    string result;
    vector <string> heya;
    
    int please;
    for( int i = 0; i < 9; ++i){
        
        scanf("%d",  &please);
        clocks.push_back( please );
    }
    
    int sw[10] = { 0 };
    //memset( sw, 0, 10 );
   
   
    for( sw[1]=0; sw[1]<4; ++sw[1] ){
        
        for( sw[2]=0; sw[2]<4; ++sw[2] ){
            for( sw[3]=0; sw[3]<4; ++sw[3] ){
                for( sw[4]=0; sw[4]<4; ++sw[4] ){
                    for( sw[5]=0; sw[5]<4; ++sw[5] ){
                        for( sw[6]=0; sw[6]<4; ++sw[6] ){
                            for( sw[7]=0; sw[7]<4; ++sw[7] ){
                                for( sw[8]=0; sw[8]<4; ++sw[8] ){
                                    for( sw[9]=0; sw[9]<4; ++sw[9] ){
                                        
                                        if ( check( sw[1], sw[2], sw[3], sw[4], sw[5], sw[6], sw[7], sw[8], sw[9], clocks) ){
                                            //printf("hello");
                                            string hello;
                                            for(int i=1; i<=9; ++i){
                                                
                                                if( sw[i] != 0){ 
                                                    
                                                    for( int j = 0; j < sw[i]; ++j){
                                                        
                                                        stringstream help ;
                                                        help << i ;
                                                        hello += help.str();
                                                    }
                                                }
                                            }    
                                            heya.push_back(hello); 
                                        }                                            
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    sort( heya.begin(), heya.end(), custom );
    result = heya[0]; 
    
    for( int i=0; i < result.size(); ++i){
        
        if( i != result.size() - 1)
            printf("%c " , result[i]);
        else
            printf("%c", result[i]);
    }

    return 0;
}
