#include <cstdio>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){

    ifstream infile("lektira.in");
    
    freopen("lektira.out","w",stdout);
    
    string Word, result, volatilee;
    getline(infile,Word); 

        
    volatilee = Word[0];
    
    for(int i = 1; i < Word.size() - 2; ++i){
        
        string help( Word.begin(), Word.begin() + i);
        reverse( help.begin(), help.end());
        
        if ( help.compare(volatilee) < 0){
            volatilee = help;
        }
    }
    
    result = volatilee;
    //printf("%s\n", result.c_str());
    
    int index = result.size();
    volatilee = Word[ index ];
    
    for(int i = index + 1; i < Word.size(); ++i){
        
        string help( Word.begin() + index, Word.begin() + i);
        reverse( help.begin(), help.end());
        
        if ( help.compare(volatilee) < 0){
            volatilee = help;
        }  
    }
    
    result += volatilee;
    index = result.size();
    //printf("%s\n", result.c_str());
    
        
    string help( Word.begin() + index, Word.end());
    reverse( help.begin(), help.end());

    result += help;

    printf("%s\n", result.c_str());
    
    infile.close(); 
    return 0;

}
