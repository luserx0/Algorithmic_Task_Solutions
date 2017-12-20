#include <cstdio>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAXC 1008

int n, i, j, z, k, swaps, counter, min_of_all, result;
int Adenine, Thymine, Cytosine, Guanine;

char nucleotides[MAXC];
char correct[MAXC];

void Read(){
    scanf("%d %d\n", &n, &k);
    scanf("%s", nucleotides);
    //printf("Input: %s\n", str);
}

int smallest(int x, int y, int z, int a){
    return min(min(min(x,a), y), z);
}

void Ad_Hoc(){
    result = MAXC;
    for (i=k; i>0; i--) {
        swaps = 0;
        for (j=0; j<i; j++) {   //check
            Adenine = Thymine = Guanine = Cytosine = 0;
            counter = 0; //μετρητής = 0
            for (z=j; z<n; z+=i) {
                if (nucleotides[z] == 'A') { Adenine++; }
                if (nucleotides[z] == 'C') { Cytosine++; }
                if (nucleotides[z] == 'T') { Thymine++; }
                if (nucleotides[z] == 'G') { Guanine++; }
                counter++;//μετρητής = μετρητής + 1
            }

            Adenine = counter - Adenine;
            Cytosine = counter - Cytosine;
            Guanine = counter - Guanine;
            Thymine = counter - Thymine;

            min_of_all = smallest(Thymine, Adenine, Cytosine, Guanine);
            //printf("%d %d\n", min_of_all, counter);

            swaps += min_of_all;
        }
        if (result > swaps) { result = swaps; }
    }
    printf("%d\n", result);

}

int main(){
    freopen("dna.in","r",stdin);
    freopen("dna.out","w",stdout);

    Read();

    Ad_Hoc();


    return 0;
}
