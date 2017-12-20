#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main()
{
    string line;
    int sitin,standin,r,s,t;
    ifstream infile;
    infile.open("sitin.txt");
    getline(infile,line);
        sscanf(line.c_str(),"%d %d", &r, &s);
    getline(infile,line);
        t=atoi(line.c_str());
    if (t > r*s) {
        sitin = r*s;
        standin = t - sitin;
}   else {
        sitin = t;
        standin = 0;
}
    ofstream myfile;
    myfile.open ("sitout.txt");
    myfile << setfill('0');
    myfile <<sitin<<" "<<standin;
    myfile.close();

    return 0;
}
