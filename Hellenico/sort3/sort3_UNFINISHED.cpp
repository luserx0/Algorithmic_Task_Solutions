#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
    #ifdef D
    freopen ("input","r",stdin);
    #endif
    freopen ("sort3.in","r",stdin);
    freopen ("sort3.out","w",stdout);

    long L=0;
    int i, n, c1=0, c2=0, j, a;

    scanf("%i", &n);

    vector <int> keystroke;

    for (i=0; i<n; i++){
        scanf("%i", &a);
        keystroke.push_back(a);
        if (a==1) { c1++; }
        if (a==2) { c2++; }
    }

    vector <int> sorted = keystroke;
    sort(sorted.begin(),sorted .end());




    printf("%d\n",L);



    return 0;
}
