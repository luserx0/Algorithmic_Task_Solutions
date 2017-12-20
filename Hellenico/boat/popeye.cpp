#include <cstdio>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAXC 45

stack <string> markes;
vector <string> sortedStack;

int n, out, in, i, j, k;

char str[MAXC];
string str1;

void Read(){

    scanf("%d %d", &out, &in);

    for (k=0; k<in; ++k){
        scanf("%s", str);
        markes.push(str);
    }

    for(i=0; i<n-1; ++i){
        scanf("%d %d", &out, &in);
        //printf("hi\n");
        for (j=0; j<out; ++j){
            markes.pop();
        }
        for (k=0; k<in; ++k){
            scanf("%s", str);
            markes.push(str);
            //printf("%s\n", str);
        }
    }
}


void Output(){
    while(!markes.empty()){
        str1 = markes.top();
        sortedStack.push_back(str1);
        //printf("%s\n",str1.c_str());
        markes.pop();
    }

    sort(sortedStack.begin(),sortedStack.end());

    for(i=0; i<sortedStack.size(); i++){
        str1 = sortedStack[i];
        printf("%s\n", str1.c_str());

    }
}


int main(){
    freopen("boat.in","r",stdin);
    freopen("boat.out","w",stdout);

    scanf("%d", &n);

    Read();//check

    Output();//douleyei alla vgazei periergous xaraktires kai dn 3erw ti einai.

    return 0;
}
