#include <cstdio>
using namespace std;

int N,Q;
int A[1000001];
int odd[1000001];
int main () {
	freopen("oddhouse.in","r",stdin);
	freopen("oddhouse.out","w",stdout);
	scanf("%d %d",&N,&Q);
	for (int i=1;i<=N;++i) {
		scanf("%d",&A[i]);
		if (A[i]%2 == 1) odd[i] = odd[i-1] + 1;
		else odd[i] = odd[i-1];
	}
	for (int i=1;i<=Q;++i) {
		int a,b;
		scanf("%d %d",&a,&b);
		int oddcnt, evencnt;
		oddcnt = odd[b] - odd[a-1];
		evencnt = b-a+1 - oddcnt;
		if (oddcnt > evencnt) printf("odd\n");
		else if (oddcnt < evencnt) printf("even\n");
		else printf("equal\n");
	}
	return 0;
}
