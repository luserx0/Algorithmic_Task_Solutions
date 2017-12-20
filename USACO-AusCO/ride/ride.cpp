/*
ID: luserx01
LANG: C++
TASK: ride
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    string line;
    long a,b;
    int i,help2,ia,ib;
    char help;
    ifstream infile;
    infile.open("ride.in");


    getline(infile,line);
    vector<char> v;
    ia=line.size();
    for(i=0;i<ia;i++){
        v.push_back(line[i]);
        cout<<v[i]<<'\n';
    }

    vector<char> c;
    getline(infile,line);
    ib=line.size();
    for(i=0;i<ib;i++){
        c.push_back(line[i]);
        cout<<c[i]<<'\n';
    }



    a=b=1;
    for (i=0;i<ia;i++){
        help = v[i];
        help2=(int)help-'A'+1;
        a*=help2;
        cout <<a<<'\n';
    }
    for (i=0;i<ib;i++){
        help = c[i];
        help2=(int)help-'A'+1;
        b*=help2;
        cout <<b<<'\n';
    }


    ofstream myfile;
    myfile.open ("ride.out");
    if (a%47==b%47)
        myfile<<"GO"<<'\n';
    else
        myfile<<"STAY"<<'\n';
    myfile.close();
    return 0;
}

