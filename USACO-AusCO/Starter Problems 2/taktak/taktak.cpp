#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#define N

using namespace std;





int main(){
    string line;
    int i,j;
    ifstream infile;

    infile.open("taktakin.txt");
    getline(infile,line);
        int n=atoi(line.c_str());









    ofstream myfile;
    myfile.open ("taktakout.txt");
    for (i=0;i<n;i++)
        myfile<<i<<'\n';

    myfile.close();

    return 0;

}
