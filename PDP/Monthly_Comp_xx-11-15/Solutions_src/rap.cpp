#include <stdio.h>

#define MAXN 60005
#define MAXVAL 20000
#define MAXNODES 1150000

int N, M, X, A[MAXN], sum[MAXNODES], left[MAXNODES], right[MAXNODES], newNode;
// Root of time i has index i :). So the newNode variable begins from M+1

inline int uIndex() {
	return ((10301LL*X) % N) + 1;
}

inline int uValue() {
	return ((10889LL*X) % MAXVAL) + 1;
}

inline int qX() {
	return ((33617LL * X ) % N) + 1;
}

inline int qY(int queryX) {
	return queryX + ((58049LL * X ) % (N-queryX+1));
}

inline int qT(int mod) {
	return (81517LL * X) % mod;
}

//Classic segment tree, nothing new!
int Query(int v, int from, int to, int vx=1, int vy=N) {
	if ( vx==from && vy==to ) {
		return sum[v];
	}
	
	int mid = (vx+vy) / 2;
	if ( to <= mid ) {
		return Query(left[v], from, to, vx, mid);
	}
	else if ( from > mid ) {
		return Query(right[v], from, to, mid+1, vy);
	}
	return Query(left[v], from, mid, vx, mid) + Query(right[v], mid+1, to, mid+1, vy);
}

//The only difference with the classic Set function of a segment tree is the v_old parameter
void Set(int v, int v_old, int pos, int val, int vx=1, int vy=N) {
	if ( vx == vy ) {
		sum[v] = val;
		return;
	}
	int mid = (vx+vy)/2;
	if ( pos <= mid ) {
		right[v] = right[v_old];
		left[v] = ++newNode;
		Set ( left[v], left[v_old], pos, val, vx, mid );
	}
	else {
		left[v] = left[v_old];
		right[v] = ++newNode;
		Set ( right[v], right[v_old], pos, val, mid+1, vy );
	}
	sum[v] = sum[left[v]] + sum[right[v]];
}

void Update (int ind, int val, int ttime ) {
	Set(ttime, ttime-1,ind,val);
}

void Build (int v=0, int x=1, int y=N) {
	if ( x < y ) {
		int mid = (x+y)/2;

		left[v] = ++newNode;
		Build(left[v],x,mid);

		right[v] = ++newNode;		
		Build(right[v],mid+1,y);

		sum[v] = sum[left[v]] + sum[right[v]];
	}
	else {
		scanf ("%d", &sum[v]);
	}
}

void Read () {
	int i, a, b;
	
	scanf ("%d %d", &N, &M);
	newNode = M;
	Build();
	
	scanf ("%d %d", &a, &b);
	X = Query(0,a,b);
	printf ("%d\n", X);
}

void Solve () {
	int i, updateIndex, updateValue, queryX, queryY, queryT;
	
	for ( i=1; i<=M; ++i ) {
		updateIndex = uIndex();
		updateValue = uValue();
		queryX = qX();
		queryY = qY(queryX);
		queryT = qT(i+1);

		Update( updateIndex, updateValue, i );
		X = Query ( queryT, queryX, queryY );
		printf ("%d\n", X);
	}
}

int main() {
	freopen ("rap.in","r",stdin);
	freopen ("rap.out", "w", stdout);
	
	Read();
	Solve();
}
