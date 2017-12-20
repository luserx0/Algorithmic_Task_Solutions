#include "hiddenlib.h"

using namespace std;

int main(){
    long lo, hi, mid;
    long N = getN();
    bool FLAG = false;
    
    if (ishidden(1) == true){
        FLAG = true;
    }
    if (ishidden(N) == true){
        FLAG = true;
    }
    
    lo = 1;
    hi = N;
    
    while (FLAG != 1){
        
        short help = compare(lo,hi);
        mid = (lo+hi) / 2;
        
        if(help == 1){
            FLAG = ishidden(lo);
            hi = mid;
        }
        
        if(help == -1){
            FLAG = ishidden(hi);
            lo = mid;       
        }
        
        if(help == 0){
            FLAG =ishidden(mid);
        }   
    }
    
    return 0;
}
