#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int getMax(int A[], int n) {
  int max = 0;
  for (int i = 0; i < n; i++) {
     if (A[i] > max) max = A[i];
  }
  return max;
}


int main(){
    int i,ia,ic;
    int minmaxabc, S, help;
    string line;
    ifstream infile;

    infile.open("share.in");
    getline(infile,line);
    int n=atoi(line.c_str());

    S=i=help=0;

    int dailyprofit[n], A[n];

    int k=0;
    while (getline(infile,line)){
        int a;
        a=atoi(line.c_str());
        dailyprofit[k]=a;
        S+=a;
        A[k]=S;
        k++;
        }


    int lo = getMax(dailyprofit, n);
    int hi = S;

    while (lo < hi) {
    int mid = lo + (hi-lo)/2;
    int requiredPainters = getRequiredPainters(A, n, mid);
    if (requiredPainters <= k)
      hi = mid;
    else
      lo = mid+1;
  }

    ofstream myfile;
    myfile.open ("share.out");
    myfile << minmaxabc<<'\n';
    myfile.close();

    return 0;
}
