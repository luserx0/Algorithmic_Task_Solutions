#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX 1000005

int main(){
    
    freopen("aris.in","r",stdin);
    freopen("aris.out","w",stdout);
    
    long N, M, K;

    scanf("%d %d", &N, &M);

    long teams[MAX] = {0};

    for (long i = 0; i < N; ++i){
        
        scanf("%d", &K);
        ++teams[ K ];
    }
    
    long max = 0, count = 0;
    long min = MAX;
    
    max = *max_element( teams, teams + M+1);
    
    for (long i = 0; i <= M; i++){
        
        if( teams[i] != 0){
            ++count;
            
            if( teams[i] < min)
                min = teams[i];
        }
    }

    printf("%d %d %d", count, min, max);
    
    return 0; 
}
