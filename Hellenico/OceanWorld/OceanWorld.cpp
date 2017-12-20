#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main(){
    string line;
    int result;
    ifstream ticketsin;
    ticketsin.open("tickets.in");

    getline(ticketsin,line);
        int N=atoi(line.c_str());
        N>=0;
    getline(ticketsin,line);
        int A, B, C, D;
        sscanf(line.c_str(),"%d %d %d %d", &A, &B, &C, &D);
    if (N<0)
        result=0;
    if (N>0 and N<A)
        result=N*10;
    if (N>=A)
        result=N*9;
    if (N>=B or N>A*3/4)
        result=N*8;
    if (N>=C or N>B*3/4)
        result=N*7;
    if (N>=D or N>C*3/4)
        result=N*5;


    ofstream ticketsout;
    ticketsout.open ("tickets.out");
    ticketsout<<result;
    ticketsout.close();


}
