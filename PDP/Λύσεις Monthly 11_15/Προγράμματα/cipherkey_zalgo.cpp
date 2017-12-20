#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 1000001

int N;
char M[2 * MAXN + 1];
char Mrev[2 * MAXN + 1];
int Z[2 * MAXN + 1];
int Zrev[2 * MAXN + 1];
char S[MAXN], T[MAXN];
int S_size, T_size;

void z_algorithm (int n, char *in, int *z) {
    int L = 0,R = 0;
    for (int i=1;i<n;++i) {
        if (R < i) {
            L = R = i;
            while (R < n && in[R] == in[R-L]) ++R;
            --R;
            z[i] = R - L + 1;
        }
        else {
            int k = i - L;
            if (z[k] < R - i + 1) z[i] = z[k];
            else {
                L = i;
                while (R < n && in[R] == in[R-L]) ++R;
                --R;
                z[i] = R - L + 1;
            }
        }
    }
}

int main () {
    freopen("cipherkey.in","r",stdin);
    freopen("cipherkey.out","w",stdout);
    scanf("%s",S);
    S_size = strlen(S);
    scanf("%s",T);
    T_size = strlen(T);
    int N = S_size + T_size + 1;
    for (int i=0;i<T_size;++i) M[i] = T[i], Mrev[i] = T[T_size-i-1];
    for (int i=0;i<S_size;++i) M[T_size+1+i] = S[i], Mrev[T_size+1+i] = S[S_size-i-1];

    z_algorithm(N, M, Z);
    z_algorithm(N, Mrev, Zrev);
    int cnt = 0;
    for (int i=0;i<=S_size-T_size;++i) if (Z[T_size + 1 + i] + 1 + Zrev[S_size + 1 - i] >= T_size) ++cnt;
    printf("%d\n",cnt);
    return 0;
}


