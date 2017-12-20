#include<cstdio>
#include<stdlib.h>
#include<iostream>

using namespace std;

void hanoi(int diskSize, char a, char b, char c){
    if(diskSize == 1){
            
        printf("%c %c\n", a , b);
    
    }
    
    else{
        hanoi(diskSize - 1, a , c , b);
        
        printf("%c %c\n", a , b);
        
        hanoi(diskSize - 1, c , b , a);
    }
}

int main(){
    
    freopen("qubits.in","r",stdin);
    freopen("qubits.out","w",stdout);

    int N;
    
    scanf("%d", &N);

    hanoi(N, 'A', 'C', 'B');

    return 0;

}
