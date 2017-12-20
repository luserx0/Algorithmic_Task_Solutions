/*
ID: luserx01
LANG: C++
TASK: gift1
*/


#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    
    int NP;
    string name;
    map <string,int> kids;
    
    scanf("%d", &NP);
    vector <string> names;
    
    for(int i = 0; i < NP; i++){
        
        cin >> name;
        kids[ name ] = 0;
        names.push_back(name);
        //printf("%s\n", names[i].c_str());
    }
    //check
    for(int j = 0; j < NP; j++){
        
        int money, friends;
        string giver; 
        
        cin >> giver;
        cin >> money >> friends;
        
        kids[ giver ] -= money;

        if (friends != 0){
            int help = int(money / friends);
            
            //printf("%d\n", help);
            for (int k = 0; k < friends; k++){
                   
                string kid;
                cin >> kid;
                
                kids[ kid ] += help;
                money -= help;
            }
        }
        kids[ giver ] += money;
            
    }
    
    for(int l = 0; l < NP; l++){
        string helper = names[l];
        cout << names[l] << " " << kids [helper] << '\n';
    }

    return 0;
    
}
