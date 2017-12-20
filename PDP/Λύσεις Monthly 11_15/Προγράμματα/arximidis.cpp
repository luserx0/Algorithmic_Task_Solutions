#include <stdio.h>
#include <vector>
#include <string.h>

#define MAXN 50005
#define pb push_back

using namespace std;

vector<int> e[MAXN];
int N, M, nBackEdges, vis[MAXN];

void Init() {
	int i, a, b;

	scanf ("%d %d", &N, &M);
	for (i=1; i<=N; ++i) {
		e[i].clear();
	}
	memset(vis,0,sizeof(vis));
	nBackEdges = 0;

	for (i=1; i<=M; ++i) {
		scanf ("%d %d", &a, &b);
		e[a].pb(b);
		e[b].pb(a);
	}
}

void DFS (int v, int par) {
	int i, geitonas;
 
	vis[v] = 1;
	for (i=0; i<e[v].size(); ++i) {
		geitonas = e[v][i];
		if ( vis[geitonas] == 1 && geitonas != par ) {
			++nBackEdges;
		}
		else if ( !vis[ geitonas ] ) {
			DFS(geitonas, v);
		}
	}

	vis[v] = 2;
}

void Solve() {
	int i;

	for (i=1; i<=N; ++i) {
		if ( !vis[i] ) {
			DFS(i,-1);
		}
	}

	printf ("%s\n", nBackEdges>=2?"YES":"NO");
}

int main () {
	freopen("arximidis.in","r",stdin);
	freopen("arximidis.out","w",stdout);	
	int t, T;

	scanf ("%d", &T);
	for ( t=1; t<=T; ++t ) {
		Init();
		Solve();
	}

	return 0;
}
