#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;

ll convertBinary(ll k, ll arr[]) {
    int i = 0;
    while (k > 0) {
        arr[i++] = k % 2;
        k /= 2;
    }
    return i;
}

ll mod(ll a, ll k, ll n) {
    ll arr[1000];
    int length = convertBinary(k, arr);
    ll b = 1;
    ll A = a;
    if (arr[0] == 1) b = a;
    for (int i = 1; i < length; i++) {
        A = (A * A) % n;
        if (arr[i] == 1) {
            b = (A * b) % n;
        }
    }
    return b;
}

int millerRabin(ll n, ll a) {
    ll r = n - 1;
    int s = 0;
    while (r % 2 == 0) {
        s++;
        r /= 2;
    }
    ll y = mod(a, r, n);
    if (y == 1 || y == n - 1) return 1;
    for (int i = 1; i < s; i++) {
        y = (y * y) % n;
        if (y == 1) return 0;
        if (y == n - 1) return 1;
    }
    return 0;
}

bool checkPrime(ll n) {
    if (n == 2 || n == 3) return 1;
    if (n < 2 || n % 2 == 0) return 0;
    for (int i = 0; i < 5; i++) {
        ll a = 2 + rand() % (n - 3);
        if (!millerRabin(n, a)) return 0;
    }
    return 1;
}

ll gcd(ll a, ll b) {
    ll r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll power(int a, int b) {
    ll result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

void convertArr(ll a, ll arr[], int t) {
    for (int i = 0; i < t; i++) {
        arr[i] = a % power(2,8);
        a /= power(2,8);
    }
}

void multiplyArrays(ll a, ll b, ll A[], ll B[], ll C[], int t) {
    convertArr(a, A, t);
    convertArr(b, B, t);
    for (int i = 0; i < 2 * t; i++) C[i] = 0;

    for (int i = 0; i < t; i++) {
        ll u = 0;
        for (int j = 0; j < t; j++) {
            ll uv = A[i] * B[j] + C[i + j] + u;
            ll v = uv % power(2,8;
            u = uv / power(2,8);
            C[i + j] = v;
        }
        C[i + t] = u;
    }
}

ll convertNumber(ll C[]) {
    ll number = 0;
    for (int i = 0; i < 8; i++) {
        number += C[i] * power( 2 , i * 8);
    }
    return number;
}

ll inverseMod(ll a, ll p) {
    ll u = a, v = p;
    ll x1 = 1, x2 = 0;
    while (u != 0) {
        ll q = v / u;
        ll r = v - q * u;
        ll x = x2 - q * x1;
        v = u; u = r;
        x2 = x1; x1 = x;
    }
    if (v != 1) return -1;
    if (x2 < 0) x2 += p;
    return x2;
}

int main() {
    ll A[1000], B[1000], C[1000];
    ll p, q;

    printf("Nhap so nguyen to p: ");
    scanf("%lld", &p);
    while (!checkPrime(p)) {
        printf("Nhap lai so nguyen to p: ");
        scanf("%lld", &p);
    }

    printf("Nhap so nguyen to q: ");
    scanf("%lld", &q);
    while (!checkPrime(q)) {
        printf("Nhap lai so nguyen to q: ");
        scanf("%lld", &q);
    }

    multiplyArrays(p, q, A, B, C, 4);
    ll n = convertNumber(C);

    multiplyArrays(p - 1, q - 1, A, B, C, 4);
    ll phi = convertNumber(C);

    ll e;
    printf("Nhap so nguyen e: ");
    scanf("%lld", &e);
    while (gcd(e, phi) != 1) {
        printf("Nhap lai so nguyen e: ");
        scanf("%lld", &e);
    }

    ll d = inverseMod(e, phi);

    printf("n = %lld\n", n);
    printf("d = %lld\n", d);

    return 0;
}

