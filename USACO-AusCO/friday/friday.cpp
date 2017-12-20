/*
ID: luserx01
LANG: C++
TASK: friday
*/

#include <stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;

bool find_if_leap(int yr){
    bool result = false;
    
    if ((yr % 4 == 0 and (yr % 100 != 0)) or (yr % 400 == 0)){
        result = true;
    }
    
    return result;
}

int find_month_days( int m , bool year ){
    int monthdays = 31;

    if( m == 4 or m == 6 or m == 9 or m == 11){
        monthdays--;
    }
    if( m == 2 ) {
        if (year) {
            monthdays = 29;    
        }
        else
            monthdays = 28;
    }
    return monthdays;
}

int main(){
        
    //redirection streams
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);

    //variablu initialization

    int N, i;
    int days[7] = {0 , 0 , 0 , 0 , 0 , 0 , 0};
        
    //read input
    scanf("%d", &N);
    N += 1900;
    
    i = 0;
    days[i]++;
    //alup
    for (int years = 1900; years < N; ++years){
        
        bool leap = find_if_leap ( years );
        //if (leap)
          //printf("yes %d\n", years);
        
        for (int month = 1; month <= 12; month++){
            
            if ( month == 12 && years == N-1 )
                break;
            
            int month_days = find_month_days( month , leap );
            i = ( i + ( month_days % 7 )) % 7;   
            days[i]++;
            //printf("%d %d %d\n", i, month, years);

        }
    }
    
    printf("%d %d %d %d %d %d %d\n", days[0], days[1], days[2], days[3], days[4], days[5], days[6]);

    return 0;
}
