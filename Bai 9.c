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

ll inverseMod(ll a, ll p) {
    ll u = a, v = p;
    ll x1 = 1, x2 = 0;
    while (u != 0) {
        ll q = v / u;
        ll r = v - q * u;
        ll x = x2 - q * x1;
        v = u;
        u = r;
        x2 = x1;
        x1 = x;
    }
    if (x2 < 0) x2 += p;
    return x2;
}

int main() {
    ll p,g, x, a, b;
    scanf("%lld", &p);
    scanf("%lld", &g);
    scanf("%lld", &x);
    scanf("%lld %lld",&a,&b);
    ll s = mod(a, x, p);
    ll result = inverseMod(s, p);
    ll m = (b * result) % p;

    printf("%lld\n", m);

    return 0;
}

