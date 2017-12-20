    #include<cstdio>  
    #include<algorithm>  
    #include<iostream>  
    using namespace std;  
      
    #define MAXAB 200008  
    #define utilizer 100000  
      
    int main(){  
         
        freopen("crocodiles.in","r",stdin);  
        freopen("crocodiles.out","w",stdout);  
          
        long lc_max, lc_min, N, maxY, help;  
        long years[MAXAB] = {0};  
        
        lc_max = 0;
        lc_min = MAXAB;
        //scanf("%d", &N);  
          
        for(cin >> N; N; --N){  
              
            signed long A,B;  
            scanf("%d %d", &A, &B);  
              
            //printf("%d %d\n", A, B);  
               
            A += utilizer;  
            B += utilizer;  
            
            ++ years[A];
            -- years[B];
            
            if ( A < lc_min )
                lc_min = A;

            if ( B > lc_max )
                lc_max = B;
        }  
        
        help = maxY = 0;
        for ( long i = lc_min; i < lc_max; ++i){

            if ( help + years[ i ] > years [ i ] ){
                help += years[i];
            }
            
            else{
                help = years[i];
            }

            maxY = max( help, maxY ); 
        }    
          
        printf("%d\n", maxY);  
          
        return 0;  
    }  


