#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define MAXS 25

string some_Function(string dolphin){
    
    int counter = dolphin.length();
    string temp = dolphin;
    string Min = dolphin;
    char bubble;
    
    for(int j=0 ; j<counter; j++){
        bubble = temp[0];    
        temp.push_back(bubble);
        temp.erase(temp.begin());
        
        if(temp < Min)
            Min = temp;
        
        if(temp == dolphin) break;
    }
    
    return Min;

}

int main(){
    
    string line;
    ifstream infile;
    infile.open("names.in");
    
    freopen("names.out", "w", stdout);
    
    getline(infile,line);
    int N = atoi(line.c_str());
    
    string Name, MIN("ZZZ"), extra, id;
    for(int i=0; i<N; i++){
        
        getline(infile,Name);
        extra = some_Function(Name);
        
        //cout << Name << '\n';
        if(extra < MIN){
            MIN = extra;
            id = Name;
        }
    }
    printf("%s", id.c_str()); 
    return 0;
}
