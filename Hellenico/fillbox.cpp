#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAXM 1000008
#define ll long long

ll small( ll A, ll B, ll C ){
    
    ll minM = MAXM;
    if( A < minM )
        minM = A;
    if( B < minM )
        minM = B;
    if( C < minM )
        minM = C;

    return minM;
}

ll big( ll A, ll B, ll C ){
    
    ll maxM = A;
    if( B > maxM )
        maxM = B;
    if( C > maxM )
        maxM = C;

    return maxM;
}

int main(){
    
    freopen("fillbox.in", "r", stdin);
    freopen("fillbox.out", "w", stdout);
    
    ll zero = 0;
    vector<ll> Qbs;
    ll result=0, help;
    ll L, W, H, i, j,maxQ=0;
    
    cin >> L >> W >> H;
    
    maxQ = small(L,W,H);
    
    i=0;
    while( pow(2,i) <= maxQ ){
        
  //      cout << i;
        Qbs.push_back( pow(2,i) );
        ++i;
    }
    
    ll aux[ MAXM ] = {0};
    
    j = Qbs.size() - 1;
    while( j != -1 ){
        
        ll Qb = Qbs[j]; //ladaki na glistraei
        
        help = (long long)L/Qb * (long long)W/Qb * (long long)H/Qb;
        result += help - aux[j+1];
        
        aux[j] = (help) * 8;

//        cout << "Qb: " << Qb << " Result: " << help - aux[j+1] << " Aux [ " << j << " ]: " << aux[j+1] << '\n'; //formatted odata
        
        --j;
    }
    
    printf("%lld\n", result);
    return 0;
}
