#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;

int convertBinary(ll k, int bin[]) {
    int i = 0;
    while (k > 0) {
        bin[i++] = k % 2;
        k /= 2;
    }
    return i;
}

ll mod(ll a, ll k, ll n) {
    int bin[1000];
    int len = convertBinary(k, bin);
    ll b = 1;
    ll A = a;

    if (bin[0] == 1) b = a;

    for (int i = 1; i < len; i++) {
        A = (A * A) % n;
        if (bin[i] == 1) {
            b = (b * A) % n;
        }
    }
    return b;
}

int main() {
    ll p, g, k, y, m ;
    scanf("%lld", &p);
    scanf("%lld", &g);
    scanf("%lld", &k);
    scanf("%lld", &y);
    scanf("%lld", &m);
    ll a = mod(g, k, p);
    ll b = ( m * mod(y,k,p)) % p;
    printf("%lld\n",a);
    printf("%lld\n",b);

    return 0;
}


