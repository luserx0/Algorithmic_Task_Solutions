#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int maxx(long a, long b, long c){
    long help=a;
    if (b>help)
        help=b;
    if (c>help)
        help=c;

    return help;
}



int main(){
    long i,ia,ic;
    long a , b , c , minmaxabc, S, max1, max2;
    string line;
    ifstream infile;

    infile.open("share.in");
    getline(infile,line);
    long n=atoi(line.c_str());

    S=i=0;
    vector<long> dailyprofit(n);
    vector<long> A(n);
    long k=0;

    while (getline(infile,line)){
        long a;
        a=atoi(line.c_str());
        dailyprofit[k]=a;
        S+=a;
        A[k]=S;
        k++;
        }


    vector<long> C(n);
    for(i = 0;i < n; i++){
        c = S-A[i]+dailyprofit[i];
        C[i]=c;
        }

    for (i = 0;i < n ; i++){
        if (A[i]>C[i]){
            ia=ic=i;
            break;
            }
        }


    b=S-A[ia]-C[ic];
    if(b<0){
        ia--;
        ic++;
    }

    while(true){
        b=S-A[ia]-C[ic];
        minmaxabc = maxx( A[ia], b, C[ic]);
        max1 = maxx( A[ia-1], S-A[ia-1]-C[ic], C[ic]);
        max2 = maxx( A[ia], S-A[ia]-C[ic+1], C[ic+1]);


        if(minmaxabc < max1 && minmaxabc < max2)
            break;
        else{
            if(max1 < minmaxabc){
                minmaxabc=max1;
                ia--;
                }
            else{
                minmaxabc=max2;
                ic++;
                }
        }
    }

    ofstream myfile;
    myfile.open ("share.out");
    myfile << minmaxabc<<'\n';
    myfile.close();

    return 0;
}
