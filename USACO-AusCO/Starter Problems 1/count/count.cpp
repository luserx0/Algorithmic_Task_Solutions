#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;


int main(){
    string line;
    int i;
    ifstream infile;

    infile.open("countin.txt");
    getline(infile,line);
        int n=atoi(line.c_str());


    ofstream myfile;
    myfile.open ("countout.txt");
    for (i=1;i<=n;i++)
        myfile<<i<<'\n';

    myfile.close();

    return 0;

}
