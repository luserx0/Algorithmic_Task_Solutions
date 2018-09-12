#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
#define MAXN 1000001
typedef unsigned long long ull;

char S[MAXN], T[MAXN];
int P = 31;
int S_size, T_size;
set<ull> pattern;

int main () {
    freopen("cipherkey.in","r",stdin);
    freopen("cipherkey.out","w",stdout);
    scanf("%s",S);
    S_size = strlen(S);
    scanf("%s",T);
    T_size = strlen(T);
    ull h = 0;
    for (int i=0;i<T_size;++i) h = h * P + T[i] - 'a' + 1;
    pattern.insert(h);
    ull P_pow = 1;
    for (int i=T_size-1;i>=0;--i) {
        for (int j='a';j<='z';++j) if (j != T[i]) pattern.insert(h - P_pow * (T[i] - j));
        P_pow *= P;
    }
    h = 0;
    for (int i=0;i<T_size;++i) h = h * P + S[i] - 'a' + 1;
    int cnt = 0;
    for (int i=0;i+T_size-1<S_size;++i) {
        if (pattern.find(h) != pattern.end()) ++cnt;
        h = h * P - P_pow * (S[i] - 'a' + 1) + S[i+T_size] - 'a' + 1;
    }
    printf("%d\n",cnt);
    return 0;
}

