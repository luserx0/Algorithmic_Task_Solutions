    #include <cstdio>  
    #include <algorithm>  
    #include <queue>  
    #include <iostream>  
    using namespace std;  
      
    #define pb push_back  
    #define MAXN 108  
      
    long board[ MAXN ] = {0};  
      
    bool odd( long a ){  
        return( a % 2 == 1 );      
    }  
      
    int main(){  
          
        //freopen("ngame.in", "r", stdin);  
        //freopen("ngame.out", "w", stdout);  
          
        
        long N, i, S=0, OddSum=0, EvenSum=0, head, rear, help=0, help2=0;  
        bool Oswitch, O2switch, turn1;  
          
        scanf("%ld", &N);  
      
        for( i = 1; i <= N; ++i ){  
              
            scanf("%ld", &board[ i ] );  
            S += board[ i ];  
        }  
         
        // here we go

        for( i = 1; i <= N; ++i ){  
            
            if( odd( i ) )  
                OddSum += board[ i ];  
            else  
                EvenSum += board[ i ];  
        }  
        
        Oswitch = OddSum > EvenSum;  //bool
          
          
        head = 1;  
        rear = N;  
        turn1 = true;  
          
        for( i = 1; i <= N; ++i ){  
              
            if( turn1 ){  
                if( Oswitch ){  
                  
                    if( odd( head ) ){  
                        help += board[ head ];  
                        head++;  
                    }  
                    else{  
                        help += board[ rear ];  
                        rear--;  
                    }  
                      
                }  
              
                else{  
                  
                    if( odd( head ) ){  
                        help += board[ rear ];  
                        rear--;  
                    }  
                    else{  
                        help += board[ head ];  
                        head++;  
                    }  
                }  
                turn1 = false;  
                if( i == 1 )  
                  Oswitch ? O2switch = (OddSum - help) > EvenSum : O2switch = OddSum >= ( EvenSum - help );  
            }  
            else{  
                if( O2switch ){  
                  
                    if( odd( head ) ){  
                        help2 += board[ head ];  
                        head++;  
                    }  
                    else{  
                        help2 += board[ rear ];  
                        rear--;  
                    }  
                  
                }  
              
                else{  
                  
                    if( odd( head ) ){  
                        help2 += board[ rear ];  
                        rear--;  
                    }  
                    else{  
                        help2 += board[ head ];  
                        head++;  
                    }  
                }  
                turn1 = true;  
            }  
            //cout << help << " " << help2 << '\n';  
        }        
          
        printf("%ld %ld", help, S-help );  
      
        return 0;  
    }  
