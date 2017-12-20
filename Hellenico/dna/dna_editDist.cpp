#include <cstdio>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAXC 1008
#define INSERT_COST 1
#define DELETE_COST 1
#define REPLACE_COST 1

int n, i, j, k, lenstr, lenc;

char str[MAXC];
char correct[MAXC];

void Read(){
    scanf("%d %d\n", &n, &k);
    scanf("%s", str);
    //printf("Input: %s\n", str);
}

void ShouldBE(){
    for (i=0; i<n-k; i++){
        if(i < k) {correct[i] = str[i];}

        correct[i+k] = str [i];
    }
    printf("ShouldBE: %s\n", correct);
}

int editDistance() {
   // cost matrix
   // row -> str & col -> correct
   int cost[lenstr][lenc];
   int i,j;
   // initialize the cost matrix
   for (i=0;i<lenstr;i++) {
      for(j=0;j<lenc;j++) {
         if (i == 0) {
            // source string is NULL
            // so we need 'j' insert operations
            cost[i][j] = j*INSERT_COST;
         } else if (j == 0) {
            // target string is NULL
            // so we need 'i' delete operations
            cost[i][j] = i*DELETE_COST;
         } else {
            cost[i][j] = -1;
         }
      }
   } //initialization done

   //compute cost(i,j) and eventually return cost(m,n)
   for(i=1;i<lenstr;i++) {
      for(j=1;j<lenc;j++) {
         int x = cost[i-1][j] + DELETE_COST;
         int y = cost[i][j-1] + INSERT_COST;
         // if str(i-1) != correct(j-1), add the replace cost
         // we are comparing str[i-1] and correct[j-1] since
         // the array index starts from 0
         int z = cost[i-1][j-1] + (str[i-1] != correct[j-1])*REPLACE_COST;
         // as per our recursive formula
         cost[i][j] = min(x, min(y,z));
      }
   }

   // last cell of the matrix holds the answer
   return cost[lenstr-1][lenc-1];
}



int main(){
    freopen("dna.in","r",stdin);
    freopen("dna.out","w",stdout);

    Read();

    ShouldBE();

    lenstr = strlen(str);
    lenc = strlen(correct);

    int min_cost = editDistance();

    printf("%d\n", min_cost);

    return 0;
}
