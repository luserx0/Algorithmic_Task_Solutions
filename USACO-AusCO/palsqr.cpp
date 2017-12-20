/*
 LANG: C++
 ID: luserx01
 TASK: palsquare
*/

#include <algorithm>
#include <iostream>
#include "stdio.h"
#include <string>
#include <sstream>

using namespace std;

int base;

char GT10( int R ){

    if( R == 10 )
        return 'A';
    if( R == 11 )
        return 'B';
    if( R == 12 )
        return 'C';
    if( R == 13 )
        return 'D';
    if( R == 14 )
        return 'E';
    if( R == 15 )
        return 'F';
    if( R == 16)
        return 'G';
    if( R == 17 )
        return 'H';
    if( R == 18 )
        return 'I';
    if( R == 19 )
        return 'J';
}

string convert( long N ){
    
    string result = "";

    while( 1 ){    
        
        stringstream ss;
        if( N % base >= 10 )
            ss << GT10( N % base );
        else
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

bool check( string hello ){

    if( hello == string( hello.rbegin(), hello.rend()) )
        return true;
    else
        return false;

}
int main(){
    
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    
    scanf("%d", &base);

    for( int i = 1; i <= 300; ++i ){

        string NinB = convert( i*i );

        if( check( NinB ) )
            cout << convert( i ) << " " << NinB << '\n';
        
    }
    return 0;
}
