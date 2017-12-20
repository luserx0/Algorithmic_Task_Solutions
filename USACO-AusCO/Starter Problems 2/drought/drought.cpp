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
    long long result,i;

    infile.open("rainin.txt");
    getline(infile,line);
    long llint;
    long S;
    int n;
    sscanf(line.c_str(),"%d %d", &n, &llint);


    int putin[n];
    int k=0;
    while (getline(infile,line))
    {
        long a;
        a=atoi(line.c_str());
        putin[k]=a;
        k++;
    }


    i=S=result=0;
    while (S<llint)
    {
        S=S + putin[i];
        result++;
        i++;
    }

    ofstream myfile;
    myfile.open ("rainout.txt");
    myfile<<result;
    cout<<result;
    myfile.close();



    return 0;
}

