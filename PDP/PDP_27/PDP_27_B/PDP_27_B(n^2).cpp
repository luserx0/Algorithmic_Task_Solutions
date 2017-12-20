#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int maxx(int a, int b, int c){
    int help=a;
    if (b>help)
        help=b;
    if (c>help)
        help=c;

    return help;
}


int main(){
    long i,j;
    long a , b , c , minmaxabc, maxabc, S;
    string line;
    ifstream infile;

    infile.open("shares1.in");
    getline(infile,line);
    long n=atoi(line.c_str());

    long dailyprofit[n];
    long k=0;
    while (getline(infile,line)){
        long  a;
        a=atoi(line.c_str());
        dailyprofit[k]=a;
        k++;
    }

    a=b=c=S=i=0;



    for (i = 0; i < n; i++)
        S += dailyprofit[i];
    minmaxabc = S;
    cout<<S<<'\n';


    for(i = 0;i < n-1; i++){
        a += dailyprofit[i];
        b = dailyprofit[i+1];
        c = S - a - b;

        for (j = i+1;j < n-1; j++){

                //cout << "a:"<<a<<"b:"<<b<<"c:"<<c<<'\n';
                if  (c > b){
                    b+=dailyprofit[j+1];
                    c=S-a-b;
                }
                else{
                    maxabc=maxx(a,b,c);
                    if (maxabc < minmaxabc)
                        minmaxabc=maxabc;
                    break;
                }
        }
    }




    ofstream myfile;
    myfile.open ("share.out");
    myfile << minmaxabc<<'\n';
    cout<<minmaxabc;
    myfile.close();

    return 0;
}
