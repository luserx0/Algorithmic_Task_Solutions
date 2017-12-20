#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

#define M 11
#define END 0.00

int coins[11] = {5, 10, 20, 50, 100, 200, 500,
                    1000, 2000, 5000, 10000};
int n;

long long coinChange()
{
    int i, j;
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is consturcted
    // in bottom up manner using the base case (n = 0)
    long long table[n+1];

    // Initialize all table values as 0
    memset(table, 0, sizeof(table));

    // Base case (If given value is 0)
    table[0] = 1;

    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for ( i=0; i<M; i++)
        for ( j = coins[i]; j<=n; j++)
            table[j] += table[j - coins[i]];

    return table[n];
}



int main(){
    //freopen("dollars.txt","r",stdin);
    double change;

    while (scanf("%lf\n", &change) == 1){
        if (change == END){
            break;
        }
        else{
            n = (int)(change*100+0.5);

            printf("%6.2lf%17lld\n", change, coinChange());
        }
    }


    return 0;
}
