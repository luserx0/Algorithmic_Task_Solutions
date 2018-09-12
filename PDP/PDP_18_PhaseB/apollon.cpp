#include<iostream>
#include<fstream>
#define INFINITY 999

using namespace std;

int adjMatrix[][];
int predecessor[];
int dist[];
bool mark[]; //keep track of visited node
int source;
int numOfVertices;
int L;

void read(){
    string line;
    ifstream infile;
    infile.open("apollon.in");
    getline(infile,line);
    sscanf(line.c_str(),"%d %d", &numOfVertices , &L);

    for (int i=0; i<L; i++)
    {
        getline(infile,line);
        sscanf(line.c_str(),"%d %d %d", &a, &b, &w);
    }
    getline(infile,line);
    sscanf(line.c_str(),"%d %d", &source , &L);


    infile.close();
}

void initialize(){
    for(int i=0;i<numOfVertices;i++) {
        mark[i] = false;
        predecessor[i] = -1;
        dist[i] = INFINITY;
    }
    dist[source]= 0;
}


int getClosestUnmarkedNode(){
    int minDistance = INFINITY;
    int closestUnmarkedNode;
    for(int i=0;i<numOfVertices;i++) {
        if((!mark[i]) && ( minDistance >= dist[i])) {
            minDistance = dist[i];
            closestUnmarkedNode = i;
        }
    }
    return closestUnmarkedNode;
}


void calculateDistance(){
    initialize();
    int minDistance = INFINITY;
    int closestUnmarkedNode;
    int count = 0;
    while(count < numOfVertices) {
        closestUnmarkedNode = getClosestUnmarkedNode();
        mark[closestUnmarkedNode] = true;
        for(int i=0;i<numOfVertices;i++) {
            if((!mark[i]) && (adjMatrix[closestUnmarkedNode][i]>0) ) {
                if(dist[i] > dist[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i]) {
                    dist[i] = dist[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i];
                    predecessor[i] = closestUnmarkedNode;
                }
            }
        }
        count++;
    }
}


void printPath(int node){
    if(node == source)
        cout<<(char)(node + 97)<<"..";
    else if(predecessor[node] == -1)
        cout<<"No path from “<<source<<”to "<<(char)(node + 97)<<endl;
    else {
        printPath(predecessor[node]);
        cout<<(char) (node + 97)<<"..";
    }
}


void output(){
    ofstream output;
    output.open("apollon.out");




    output.close();
}


int main(){

    read();
    calculateDistance();
    output();
    return 0;
}
