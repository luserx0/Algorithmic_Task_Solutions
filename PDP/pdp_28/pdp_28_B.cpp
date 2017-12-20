#include <cstdio>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

int zero = 0;
vector <long> board;
long summa[ 2000008 ] = { 0 }, N=0, K=0;

long find_group_2K(){
    
    //find the contiguous max sum of length K*2
    long max_ending_here, max_so_far;
    max_ending_here = max_so_far = accumulate( board.begin()+1, board.begin() + 2*K + 1, 0 );
    
    for ( long x=2; x <= N - 2*K + 1; ++x) {
        max_ending_here = max_ending_here + board[x + 2*K - 1] - board[x-1];
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

void Summa( long N, long K ){  
    
    //precompute sums, such as summa[i] = summa[ i ] + summa [ i+1 ] .. summa[ i + K -1 ]
    summa[1] = accumulate( board.begin()+1, board.begin()+K+1, 0);
    for( long i = 2; i <= N-K/2; ++i ){
        summa[i] = summa[i-1] + board[i+K-1] - board[i-1];    
        
    }
}
int main(){
    
    freopen("scrabble1d.in","r",stdin);
    freopen("scrabble1d.out","w",stdout);

    long i=0, S1=0, S2=0, result=0, max = 0, max_i;
    
    board.push_back( zero ); //kill board[0] to ease up things
    
    scanf("%ld %ld", &N, &K );

    for( i = 1; i <= N; i++ ){ //read values
        long help;
        scanf("%ld", &help );
        board.push_back(help);
    }
    
    Summa( N , K ); //precompute all the sums
    
    long s2K = find_group_2K();
    
    for( i = 1; i <= N-K; ++i ){
        if( summa[i] > max ){
            max = summa[i];
            max_i = i; 
        }
    }
    S1 = max;
    
    // 0 all summas that include elements from S1 == summa[ max_i ]
    for( i = max_i; i < max_i+K; ++i ) 
        summa[ i ] = 0;
    for( i = max_i; i > max_i-K; --i )
        summa[ i ] = 0; 
    
    S2 = *max_element( summa, summa + N+1 ); 
          
    result = S1 + S2;
    if( result < s2K )  
        result = s2K;
    
    printf("%ld\n", result);           
    
    return 0;
}
