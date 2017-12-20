#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){
    string line;
    int n,d,a,b;
    ifstream infile;

    infile.open("mixin.txt");
    getline(infile,line);
        sscanf(line.c_str(),"%d %d", &n, &d);
    b=n%d;
    a=n/d;
    ofstream myfile;
    myfile.open ("mixout.txt");
    if (b!=0){
        myfile << a<<" "<<b<<"/"<<d ;

}   else{
        myfile << a;
}
    myfile.close();

    return 0;

}
