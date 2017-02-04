#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    
    int n, i, j;
    string line;

    while( getline(cin, line) ){
        
        if ( line.empty() )
            break;

        sscanf(line.c_str(), "%d %d", &i, &j );
        
        if( j == 0 ){
            getline(cin, line);
            sscanf(line.c_str(), "%d", &j );
        }

        cout << i << " " << j; 
        if( i > j )
            swap( i, j );
        
        
        int max = 0;
        for( int k = i; k <= j; ++k ){
            
            n = k;
            int count = 1;

            while( n != 1 ){    

                if ( n % 2 == 1 )
                    n = 3*n +1;
                else
                    n /= 2;
        
                count++;
        
                //cout << n << '\n';
            }
         
            if( count > max )
                max = count;

        }
        
        cout << " " << max << '\n';
    }
    return 0;
}
