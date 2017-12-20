#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define MAXn 1000000
#define MAXresult n
using namespace std;


int main(){
    long help;
    long result=1;
    string line;
    ifstream infile;

    infile.open("xxx.in");
    getline(infile,line);
    long n=atoi(line.c_str());

    vector<long> v;
    while(infile >> help)
        v.push_back(help);
    reverse(v.begin(), v.end());
    long j=v[0];

    for (int i=1 ;i<v.size() ;i++){
        if ( v[i] > j ){
            j=v[i];
            result++;}
    }

    ofstream myfile;
    myfile.open ("xxx.out");
    myfile << result;
    myfile.close();

    return 0;
}
