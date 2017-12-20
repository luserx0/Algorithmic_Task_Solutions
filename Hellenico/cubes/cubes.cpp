#include <cstdio>
#include <stdlib.h>

using namespace std;

int main(){
    
    freopen("cubes.in","r",stdin);
    freopen("cubes.out","w",stdout);
    
    int N,K;
    
    scanf("%d %d", &N, &K);

    int H[100005] = {0};
    int counter = 2, currH = K +1 ;
    H[K] = K;
    
    //printf("%d %d\n", N, H[currH]); 
    while ( H[currH] <  N ){
        
        for(int i=0; i<K; i++){
            
            H[currH] = H[currH-1]  + counter;
            
            if(H[currH] > N)
                break;
            
            //printf("%d %d\n", H[currH], H[currH -1]);
            
            currH++;
        }            
        //printf("the for broke");
        counter++;
        //H[currH]++;
    }

    printf("%d", currH-1);

    return 0;
}
       
