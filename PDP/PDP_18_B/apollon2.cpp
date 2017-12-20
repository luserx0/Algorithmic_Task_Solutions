#include <iostream>
#include <set>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MAX = 1001;
const int MAXINT = 1000000000;

int n;
vvii G(MAX);
vi D(MAX, MAXINT);

void Dijkstra(int s)
{
    set<ii> Q;
    D[s] = 0;
    Q.insert(ii(0,s));

    while(!Q.empty())
    {
        ii top = *Q.begin();
        Q.erase(Q.begin());
        int v = top.second;
        int d = top.first;

        for (vii::const_iterator it = G[v].begin(); it != G[v].end(); it++)
        {
            int v2 = it->first;
            int cost = it->second;
            if (D[v2] > D[v] + cost)
            {
                if (D[v2] != 1000000000)
                {
                    Q.erase(Q.find(ii(D[v2], v2)));
                }
                D[v2] = D[v] + cost;
                Q.insert(ii(D[v2], v2));
            }
        }
    }
}

int main()
{
    int N, L, s, t = 0;
    string line;
    ifstream infile;
    infile.open("apollon.in");
    getline(infile,line);
    sscanf(line.c_str(),"%d %d", &N,&L );

    for (int i = 0; i < L; i++)
    {
        getline(infile,line);
        int a, b, w = 0;
        scanf("%d %d %d", &a, &b, &w);
        G[a - 1].push_back(ii(b - 1, w));
        G[b - 1].push_back(ii(a - 1, w));
    }

    getline(infile,line);
    sscanf(line.c_str(),"%d %d", &s, &t);
    Dijkstra(s - 1);

    ofstream output;
    output.open("apollon.out");
    output<<D[t - 1]<<endl;
    return 0;
}
