/*
 ID: LUSERX01
 LANG: C++
 TASK: namenum
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;
string input;

bool is_in_map( char c, char wordi ){
    multimap<int,char> db;

    db.insert(make_pair( 2, 'A') );
    db.insert(pair <int, char>( 2, 'B'));
    db.insert(pair <int, char>( 2, 'C'));
    db.insert(pair <int, char>( 3, 'D'));
    db.insert(pair <int, char>( 3, 'E'));
    db.insert(pair <int, char>( 3, 'F'));
    db.insert(pair <int, char>( 4, 'G'));
    db.insert(pair <int, char>( 4, 'H'));
    db.insert(pair <int, char>( 4, 'I'));
    db.insert(pair <int, char>( 5, 'J'));
    db.insert(pair <int, char>( 5, 'K'));
    db.insert(pair <int, char>( 5, 'L'));
    db.insert(pair <int, char>( 6, 'M'));
    db.insert(pair <int, char>( 6, 'N'));
    db.insert(pair <int, char>( 6, 'O'));
    db.insert( pair <int, char>( 7, 'P'));
    db.insert( pair <int, char>( 7, 'R'));
    db.insert( pair <int, char>( 7, 'S'));
    db.insert( pair <int, char>( 8, 'T'));
    db.insert( pair <int, char>( 8, 'U'));
    db.insert( pair <int, char>( 8, 'V'));
    db.insert( pair <int, char>( 9, 'W'));
    db.insert( pair <int, char>( 9, 'X'));
    db.insert( pair <int, char>( 9, 'Y'));

    pair<multimap<int, char>::iterator, multimap<int, char>::iterator> ppp;

    int ci =  c - '0';   
    ppp = db.equal_range( ci );
    
    //cout << ci << " | " << wordi << '\n';
    for (multimap<int, char>::iterator it2 = ppp.first; it2 != ppp.second; ++it2){
        if( wordi == (*it2).second )
            return true;
    }
    return false;
}

bool check( string word ){
     
    if( input.length() != word.length() )
        return false;
    
    //cout << input << " | " << word << '\n';
    
    for( int i = 0; i < input.length(); ++i ){
        
        if( !(is_in_map( input[i], word[i] )) )
            return false;
            
    }

    return true;

}

int main(){
  
    freopen("namenum.out", "w", stdout);
    ifstream fin("namenum.in"), dict("dict.txt");
    
    bool print = false;
    string word;
    fin >> input;
    
    
    while( dict >> word ){
        if( check( word ) ){
            cout << word << '\n';
            print = true;
        }
    }
    
    if( print == false )
        cout << "NONE" << '\n'; 
return 0;
}
