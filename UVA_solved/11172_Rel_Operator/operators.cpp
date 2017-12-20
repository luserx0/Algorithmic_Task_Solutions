#include <iostream>

using namespace std;

int main(){

    int t;
    long a, b; 
    
    for( cin >> t; t; t-- ){
        
        cin >> a >> b;
        
        if( a > b )
            cout << ">" << '\n';
        else if ( a < b ) 
            cout << "<" << '\n';
        else
            cout << "=" << '\n';

    }
        
    return 0;
}
