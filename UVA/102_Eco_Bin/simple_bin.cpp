#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef map<char, long> bin;
struct hello{
   string tag;
   long value;
};

bool comp( hello a, hello b){
   if( a.value == b.value )
      return (( a.tag > b.tag ) ? false : true);
   else
      return a.value < b.value;
}

int main()
{
   long fml[3][3];
   //vector <bin> bins; 
   string line;
   while( getline(cin ,line) ){
      
      if (line.empty())
             break;
      sscanf(line.c_str(), "%ld %ld %ld %ld %ld %ld %ld %ld %ld", &fml[0][0], &fml[0][1], &fml[0][2], &fml[1][0], &fml[1][1], &fml[1][2], &fml[2][0], &fml[2][1], &fml[2][2]);
      
   
   hello arr[6]; //simple array of all the possible combinations
   arr[0].tag = "BGC"; 
   arr[0].value = fml[0][1] + fml[0][2] + fml[1][0] + fml[1][2]+ fml[2][0] + fml[2][1];
   arr[1].tag = "BCG";
   arr[1].value = fml[0][1] + fml[0][2] + fml[1][0] + fml[1][1]+ fml[2][0] + fml[2][2];
   arr[2].tag = "GBC";
   arr[2].value = fml[0][0] + fml[0][2] + fml[1][1] + fml[1][2]+ fml[2][0] + fml[2][1];
   arr[3].tag = "GCB";
   arr[3].value = fml[0][0] + fml[0][2] + fml[1][0] + fml[1][1]+ fml[2][1] + fml[2][2];
   arr[4].tag = "CBG";
   arr[4].value = fml[0][0] + fml[0][1] + fml[1][1] + fml[1][2] + fml[2][0] + fml[2][2];
   arr[5].tag = "CGB";
   arr[5].value = fml[0][0] + fml[0][1] + fml[1][0] + fml[1][2] + fml[2][1] + fml[2][2];

   sort( arr, arr + 6, comp);
   /*for (i = 0; i < 6; ++i){
      cout << arr[i].tag << "\t" << arr[i].value << '\n';
   }*/
   //print-check of the bool comp
   cout << arr[0].tag << " " << arr[0].value << '\n';
   }
   return 0;
}
