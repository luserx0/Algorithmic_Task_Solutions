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
    long maxw, i, j, trans, a;

    infile.open("elevator.in");
    getline(infile,line);
    long N=atoi(line.c_str());

    long dauphins[N];
    long k=0;
    while (getline(infile,line)){
        long a;
        a=atoi(line.c_str());
        dauphins[k]=a;
        k++;
    }
    sort ( dauphins , dauphins + k );

    if (N%2==0)
    {
        trans=N/2;
        j=N-1;
        maxw = dauphins[0] + dauphins[N-1];

        for (i = 0; i < trans; i++){
            a = dauphins [i] + dauphins [j];
            if ( a > maxw )
                maxw = a;
            j--;
        }

    }

    else if(N%2==1)
    {
        long help = N / 2;
        trans=help + 1;
        j=N-2;
        maxw=dauphins[N-1];

        for (i = 0; i < trans; i++){
            a = dauphins [i] + dauphins [j];
            if ( a > maxw ) maxw = a;
            j--;
        }
    }



    ofstream myfile;
    myfile.open ("elevator.out");
    myfile<<trans<<" "<<maxw;

    myfile.close();



    return 0;
}
