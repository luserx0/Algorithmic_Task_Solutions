#include <cstdio>

using namespace std;

int main(){
    
    freopen("aces.in","r",stdin);
    freopen("aces.out","w",stdout);
    
    long N, friendship_counter[35] = {0};

    scanf ("%d", &N);
    
    for ( long k=0 ; k<N ; k++){
        
        long n;
        int i;
        
        scanf("%d", &n);
        
        i = __builtin_popcountl(n); 
        
        friendship_counter[i]++;
        //printf("%d\n" , n);

    }
    
    
    int max = 0;
    for (int j=0; j < 35; j++){
        
        if (friendship_counter[j] > max)
            max = friendship_counter[j];
        
    }
     
    printf("%d\n", max);
    
    return 0;
}
