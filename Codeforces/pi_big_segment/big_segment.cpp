#include <stdio.h>
#include <vector>

#define pb push_back
#define maxR 1000000000

using namespace std;

struct data{
    long first;
    long second;
    long which;
};

bool compre(data a,data b){
    return (a.first<b.first);
}

int main(){
    long n, a, b, i;
    long result = -1;


    scanf("%d", &n);

    vector <data> sgmts;
    data sgmt; // struct init
    long start = maxR;
    long finish = 0;

    for (i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        sgmt.first = a;
        sgmt.second = b;
        sgmt.which = i+1;
        sgmts.pb(sgmt); // vector

        if (a < start) { start = a; }
        if (b > finish) { finish = b; }

    }

    for (i=0; i<n; i++)
        {
        if (sgmts[i].first == start && sgmts[i].second == finish)
                result = sgmts[i].which;
        }

    printf ("%i", result);



    return 0;
}
// luserx0
