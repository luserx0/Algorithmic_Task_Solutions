/*
   ID: LUSERX01
   LANG: C++
   TASK: combo
*/

/*
 * 24-11-16
 * 
 * Just generated all possible ways of valid 
 * combinations and added them to a set.
 * Kind of ad-hoc, probably solvable with 
 * advanced math too
 *
*/

#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

set <string> checkd;
int possiblus[3][5];
short N;

string itoa(int n)
{
       
   string buffer; 

   do { /* generate digits in reverse order */
   
      buffer += n % 10 + '0'; /* get next digit */
      

   } while ((n /= 10) > 0); /* delete it */
   
   reverse( buffer.begin(), buffer.end() );
   return buffer;
}

void fill_possiblus_i( int dial, short i ){
   
   possiblus[i][0] = dial;
   
   possiblus[i][1] = (dial + 1) % N;
   possiblus[i][2] = (dial + 2) % N;
   
   if( dial - 1 == 0 )
      possiblus[i][3] = N;
   else
      possiblus[i][3] = dial -1;

   if( dial - 2 <= 0 )
      possiblus[i][4] = dial-2+N;
   else
      possiblus[i][4] = dial-2;
      
}

void fill_set( int lock[3], int N){

   int i,j,k;

   for( short i = 0; i < 3; ++i){
      
      fill_possiblus_i( lock[i], i );

   }

   string buffer;
   for (i = 0; i < 5; ++i){
      for (j = 0; j < 5; ++j){
         for (k = 0; k < 5; ++k){
            
            string answer = "";
            
            buffer = itoa(possiblus[0][i]);
            answer += buffer;
            
            buffer = itoa(possiblus[1][j]);
            answer += buffer;
            
            buffer = itoa(possiblus[2][k]);
            answer += buffer;
            
            //cout << answer << '\n';
            checkd.insert( answer );
         }

      } 
   }

}

int main(){
   
   freopen("combo.in", "r", stdin);
   freopen("combo.out", "w", stdout);

   int input1[3], input2[3], i;

   cin >> N;

   for (i = 0; i < 3; ++i){
      cin >> input1[i]; 
   }
   for (i = 0; i < 3; ++i){
      cin >> input2[i];
   }
   
   fill_set(input1, N);
   fill_set(input2, N);

   cout << checkd.size() << '\n';

   return 0;
}
