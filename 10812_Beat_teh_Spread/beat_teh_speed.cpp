#include <cstdio>
#include <iostream>

using namespace std;

int main(){

    long n;
  //  freopen("output.txt", "w", stdout);

    for( cin >> n; n; --n){

        long long s,d;
        cin >> s >> d;

        if( s < d ){
            
            //if the sum is less than the absolute 
            //difference of the numbers then a < 0 or b < 0
            //but football score are >= 0.
            printf("impossible\n");
        }
        else{
            // if s = d, a or b == 0
            // with a little algebraic properties 
            // the results are pretty intuitive
            //
            long long a = (d + s) / 2;
            long long b = (s - d) / 2;

            if( a == ( s - b ) ) //my algo has a prob, so i'm making a crucial heuristic
                printf("%d %d\n", a, b);
            else
                printf("impossible\n");           
        }
    }
    return 0;
}
