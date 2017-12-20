#include <iostream>
#include <map>

using namespace std;

long even( long n )
{
   if( n % 2 == 0 )
      return true;
   else
      return false;
}

int main()
{
   unsigned int i, min;
   string word;
   
   map<char,long> pokemon;
   pokemon.insert( pair<char,long>('B',0) );
   pokemon.insert( pair<char,long>('u',0) );
   pokemon.insert( pair<char,long>('l',0) );
   pokemon.insert( pair<char,long>('b',0) );
   //pokemon.insert( pair<char,long>('a',0) );
   pokemon.insert( pair<char,long>('s',0) );
   pokemon.insert( pair<char,long>('a',0) );
   //pokemon.insert( pair<char,long>('u',0) );
   pokemon.insert( pair<char,long>('r',0) );


   cin >> word;
   for (i = 0; i < word.length(); ++i)
   {
      
      if( pokemon.find( word[i] ) != pokemon.end() )
      {
         //cout << 1;
         pokemon[ word[i] ]++;
      }
   }
   
   pokemon['a'] /= 2;
   pokemon['u'] /= 2;

   string help = "ulbasr";
   min = pokemon['B'];

   for (i = 0; i < help.length() - 1; ++i){
      
      if( pokemon[ help[i] ] < min )
         min = pokemon[help[i]];
   }
   cout << min << '\n';
   return 0;
}
