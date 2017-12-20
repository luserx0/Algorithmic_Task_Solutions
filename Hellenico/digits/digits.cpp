#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include "stdlib.h"
#include <set>

using namespace std;

bool check(int a, int b, int c){
    
    set <int> isTrue;
    
    do {
        int digit = a % 10;
        isTrue.insert( digit );
        a /= 10;
    } while (a > 0);
    
    do {
        int digit = b % 10;
        isTrue.insert( digit );
        b /= 10;
    } while (b > 0);
    
    do {  
        int digit = c % 10;
        isTrue.insert( digit );
        c /= 10;
    } while (c > 0);
    
    if( isTrue.size() == 9 && isTrue.count(0) == 0)
        return true;
    else
        return false;
}


int main(){

    freopen("digits.in", "r", stdin);
    freopen("digits.out", "w", stdout);
    
    int M, c=0, b = 9999;
    
    scanf("%d", &M);

    for(int i=1; i<=9876; i++){
        
        if( i % M == 0){
            
            if ( check(i, M, i/M) ){
              
                if( i/M < b ){
                    b = i/M;
                    c = i;
                }
            }
        }
    }
    
    if( c!= 0)
        printf("%d %d\n", b, c); 
    else
        printf("%d\n", c);
    
    return 0;
}
