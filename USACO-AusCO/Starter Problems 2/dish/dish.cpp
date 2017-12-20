#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define MAXN 100001



int main(){
    string line;
    ifstream infile;
    long i,S,maxn,minn,index;

    infile.open("dishin.txt");
    getline(infile,line);
    int N=atoi(line.c_str());

    long putin[N];
    long k=0;
    while (getline(infile,line)){
        long a;
        a=atoi(line.c_str());
        putin[k]=a;
        k++;
    }
    maxn=putin[0];
    minn=putin[0];
    S=index=0;
    for (i=0;i<N;i++)
    {   S=S+putin[i];
        if (putin[i]> maxn)
            maxn=putin[i];
        if (putin[i]<minn)
            minn=putin[i];
        index++;
    }
    S=S/index;

    ofstream myfile;
    myfile.open ("dishout.txt");
    myfile<<minn<<" "<<maxn<<" "<<S;

    myfile.close();



    return 0;
}
