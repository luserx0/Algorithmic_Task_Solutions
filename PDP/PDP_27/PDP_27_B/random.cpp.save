#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>

#define MAXA 1000001

using namespace std;

long n, i, randomas[MAXA];

void Random(){
    cin>>n;
    for (i = 0;i < n;i++)
        randomas[i]=rand() % MAXA + 1;
}
void Print(){
    ofstream myfile;
    myfile.open ("share.in");
    myfile<<n<<'\n';
    for (i=0;i<n;i++)
        myfile<<randomas[i]<<'\n';
    myfile.close();
}


int main(){
    Random();
    Print();

    return 0;
}
