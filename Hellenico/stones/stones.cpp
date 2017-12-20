#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

struct item{
    long V;
    long M;     
    float product;
};

bool compre(item s, item t){        
    return(s.product > t.product); 
}


int main(){
    
    freopen("stones.in","r",stdin);
    freopen("stones.out","w",stdout);
    
    long N, LimV, i;
    
    vector <item> vectulis; //declare our vector
    
    scanf("%d %d", &N, &LimV);
        
    for ( i = 0; i < N; i++ ){ //initialize it
        
        long a,b;
        float c;
        scanf("%d %d", &a, &b);
        
        item rock;
        rock.V = a;
        rock.M = b;
        
        c = (float)b / (float)a;
        rock.product = c;
        
        vectulis.push_back(rock);
        
    }
    
    sort(vectulis.begin(), vectulis.end(), compre); //sort so Mi/Vi > Mj/Vj, for each i<=j
        
    long load = 0,size = 0;
    float result = 0;
    i = 0;
    
    while( load < LimV && i <= N){
        
        if(vectulis[i].V < LimV - load){
            size += vectulis[i].V;
            result += vectulis[i].M;
        }
        
        else{
            
            float help = (float)(LimV - size) / (float)vectulis[i].V;
            
            size += vectulis[i].V * help;
            result += float(vectulis[i].M) * help;
            
        }
        
        load += vectulis[i].V;       
        i++;               
    }

    printf("%.3f", result);
    return 0;
}
