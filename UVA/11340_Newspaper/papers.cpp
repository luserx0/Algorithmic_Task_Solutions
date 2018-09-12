#include <cstdio>
#include <iostream>
#include <map>


using namespace std;

int main(){
   
//   freopen("input.in","r",stdin);
   short n;

   for( cin >> n; n; --n ){
      
      map<char, int> table;
   
      char help;
      for( int i=65; i<=122; ++i ){

         help = i;
         table[ help ] = 0;
   
      }
      
      int k;
      cin >> k;

      for( int i = 0; i < k; ++i ){
         
         char ch;
         int cents;
         cin >> ch >> cents;

         table[ ch ] = cents;

      }

      long m, sum=0; //text start here
      cin >> m;
        
      for( int j = 0; j <= m; ++j ){
         
         string line;
         getline(cin, line);

         for( int z = 0; z < line.length(); ++z ){
            
            char index = line[ z ];
            sum += table[ index ];
            
//            cout << table[ index ] << " " << sum << '\n';
         }
  //       cout << line << '\n'; 
      }
      
      cout << int(sum / 100) << ".";
      if( sum % 100 < 10 )
         cout << "0" << sum % 100 << "$" << '\n';
      else
         cout << sum % 100 << "$" << '\n';
   }

   return 0;
}
