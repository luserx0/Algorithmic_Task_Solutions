/*
 ID: luserx01
 TASK: dualpal
 LANG: C++
*/

#include <algorithm>
#include <cstdio>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

int N, S; //global shit

string convert( int N, int base ){
        string result = "";
        while( 1 ){    
          
            stringstream ss;
            ss << ( N % base );
            string SSt = ss.str();
            
            if( (N / base) < 1 ){
                result += SSt;
                break;
            }
            
            else{
                N /= base;
                //cout << N<< '\n';
                result += SSt;
            }
        }
      
        reverse( result.begin(), result.end() );
        return result;
}
 
bool check( string kurwa ){
    
    if( kurwa == string( kurwa.rbegin(), kurwa.rend()) )
        return true;
    else
        return false;
}
int main(){

    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    
    scanf("%d %d", &N, &S );

    while( N>0 ){
        
        ++S;   
        int countb=0;
        
        for( int base = 2; base <= 10; ++base ){
            
            string change = convert( S, base );        
            
            if( check( change ) ){
                ++countb;
            }
            if( countb >= 2 )
                break;
        }
         
        if( countb >= 2 ){
            printf("%d\n", S);
            --N;
        }
    }

    return 0;
}   
