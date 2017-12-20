#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> findLocation(string sample, char findIt)
{
   vector<int> characterLocations;
   for(int i =0; i < sample.size(); i++)
      if(sample[i] == findIt)
         characterLocations.push_back(sample[i]);
   return characterLocations;
}

int main(void)
{
   int queries, i, ast_pos;
   string good, pattern;
   vector <char> goods;
   vector <int>  quest_poss;

   cin >> good;
   for (char c : good )
      goods.push_back(c);

   cin >> pattern;
   cin >> queries;

   //find the occurences of "?"
   quest_poss = findLocation( pattern, "?");   

   //find "*" position
   ast_pos = pattern.find("*");

   for (i = 0; i < queries; ++i)
   {
      string query;
      cin >> query;

      if (query.length() > pattern.length() )
         cout << "NO\n";
      
      //check all the questionmark places
      for(

      //check the asterisk place
   
   }

   return 0;
}
