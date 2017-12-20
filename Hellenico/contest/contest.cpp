#include <cstdio>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define MAXN 1005

struct node{
    int from;
    long cost;   
};

int main(){
    
    freopen("contest.in","r",stdin);
    freopen("contest.out","w",stdout);
    
    long max=0;
    int N;
    scanf("%d", &N);
    
    node Tree[MAXN];
    Tree[1].from = 0;

    bool Non_Leaf[MAXN] = { 0 } ;
    
    
    for(int i = 0; i < N - 1; i++){
        
        int A, B, X; 
        scanf("%d %d %d", &A, &B, &X);
        
        Non_Leaf[A] = true;
        
        node n;
        
        Tree[B].from = A;
        Tree[B].cost = X;
        //printf("%d %d\n" , Tree[B].cost, B);
    }

    for(int i = 1; i < N + 1; i++){

        if ( Non_Leaf[i] == false){
            
            int j = i;
            long path = 0;
            while ( Tree[j].from != 0 ){
                        
                path += Tree[j].cost; 
                
                //printf("%d\n", path); 
                

                j = Tree[j].from;
            }
 
            if ( path > max )
                max = path;
        }
    }
    
    printf("%d\n", max);
    
    return 0;
}













