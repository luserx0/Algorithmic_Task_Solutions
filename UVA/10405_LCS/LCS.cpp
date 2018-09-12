#include <iostream>

using namespace std;


int LCS( string X, string Y ){
    
    int i,j;
    int m = X.length();
    int n = Y.length();
    
    int H[m+1][n+1];
    
    for( i = 0; i<= m; ++i )
        H[i][0] = 0;

    for( j=0; j<=n; ++j)
        H[0][j] = 0;

    for( i = 1; i <= m; ++i ){

        for( j = 1; j <= n; ++j ){
            
            if ( X[i-1] == Y[j-1] )
                H[i][j] = H[i-1][j-1] +1;
            
            else
                H[i][j] = max( H[i][j-1] , H[i-1][j] );
//            cout<< H[i][j];
        }
//        cout << '\n';
    }
    return H[m][n];
}

int main(){
       
    string line, A, B;
    
    while( getline(cin, line ) ){

        if( line.empty() )
           break;

        A = line;

        getline( cin, line );
        B = line;

        cout << LCS( A, B ) << '\n';
        
    }
    return 0;
}
