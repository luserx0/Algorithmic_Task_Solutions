#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

bool shqip(int j,int i){
    //cout<<"j="<<j<<"  "<<"i="<<i<<'\n';//check
    return (j<i);
}


int main(){
    string line;
    ifstream infile;
    int b=0;

    infile.open("acropolis.in");
    getline(infile,line);
    int n=atoi(line.c_str());
    //cout<<n<<'\n';//check

    int adata[n];
    int bdata[n];
    int k=0;
    while (getline(infile,line)){
        int a;
        a=atoi(line.c_str());
        adata[k]=a;
        bdata[k]=a;
        k++;
    }

    sort(bdata, bdata + k , shqip);

    for (int i = 0; i < n; i++)
        if (bdata[i]==1)
            b++;

    ofstream myfile;
    myfile.open ("acropolis.out");


    for (int i = 0; i < n; i++)
        if (adata[i]==1)
            myfile << adata [i]<<'\n';
        else{
            myfile << bdata [b]<<'\n';
            b++;
        }
    myfile.close();



    return 0;
}
