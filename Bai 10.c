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


int main(){
	int k ;
	scanf("%d",&k);
	ll a[k], n[k];
	for ( int i = 0 ; i < k ; i++){
		scanf("%lld %lld",&a[i],&n[i]);
	}
	ll N = 1;
	for ( int i = 0 ; i < k ; i++){
	    N *= n[i];
	}
	ll x = 0;
	for ( int i = 0 ; i < k ; i++){
		ll Ni = N / n[i];
		ll Mi = inverseMod(Ni,n[i]);
		x += a[i] * Ni * Mi ;
	}
	ll result = x % N;
	printf("%lld",result);
	
	return 0;
}
