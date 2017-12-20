#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
struct cord{
    int x1;
    int y1;
    int x2;
    int y2;


};

int main(){
    string line;
    int a, b, c, d, intr, x1_intr, x2_intr, y1_intr, y2_intr, result;
    ifstream infile;

    infile.open("bendin.txt");
    getline(infile,line);
        sscanf(line.c_str(),"%d %d %d %d", &a, &b, &c , &d );
        cord t1;
        t1.x1=a;
        t1.y1=b;
        t1.x2=c;
        t1.y2=d;
    getline(infile,line);
        sscanf(line.c_str(),"%d %d %d %d", &a, &b, &c , &d );
        cord t2;
        t2.x1=a;
        t2.y1=b;
        t2.x2=c;
        t2.y2=d;


    int triangle1=(t1.x2-t1.x1)*(t1.y2-t1.y1);
    int triangle2=(t2.x2-t2.x1)*(t2.y2-t2.y1);
    cout<<triangle1<<" "<<triangle2<<'\n';

    if (t1.x1>t2.x1)
        x1_intr=t1.x1;
    else
        x1_intr=t2.x1;

    if (t1.x2<t2.x2)
        x2_intr=t1.x2;
    else
        x2_intr=t2.x2;

    if (t1.y1>t2.y1)
        y1_intr=t1.y1;
    else
        y1_intr=t2.y1;

    if (t1.y2<t2.y2)
        y2_intr=t1.y2;
    else
        y2_intr=t2.y2;

    if (x1_intr<x2_intr && y1_intr < y2_intr)
        intr=(x2_intr-x1_intr)*(y2_intr-y1_intr);
    else
        intr=0;

    result=triangle1+triangle2-intr;
    cout<<result;



    ofstream myfile;
    myfile.open ("bendout.txt");
    myfile << result;
    myfile.close();

    return 0;

}
