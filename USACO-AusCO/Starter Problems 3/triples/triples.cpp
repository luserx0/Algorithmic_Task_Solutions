#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct dual{
    int n;
    long pos;

};


int main(){
    string line;
    ifstream filey;
    filey.open("tripin.txt");
    getline(filey,line);
        int n = atoi (line.c_str());

    long k=1, a, i, trips=0;
    vector <dual> triples;
    dual data;


    while (getline(filey,line)){
        data.n=atoi(line.c_str());
        if (data.n % 3 == 0){
            data.pos=k;
            triples.push_back(data);
            ++trips;

        }
        ++k;
    }





    ofstream outfile;
    outfile.open("tripout.txt");

    if (trips == 0)
        outfile << "Nothing here!"<< '\n';
    else
        outfile<<trips<<'\n';
        for (i=0; i<triples.size(); ++i)
            outfile<<triples[i].pos<<" ";

    outfile.close();

    return 0;
}
