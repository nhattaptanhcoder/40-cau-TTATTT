#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;

int convertBinary(ll k, int arr[]) {
    int i = 0;
    while (k != 0) {
        arr[i++] = k % 2;
        k /= 2;
    }
    return i;
}

ll mod(ll a, ll k, ll n) {
    int arr[1000];
    int length = convertBinary(k, arr);
    ll b = 1;
    ll A = a;
    if (arr[0] == 1) {
        b = a;
    }
    for (int i = 1; i < length; i++) {
        A = (A * A) % n;
        if (arr[i] == 1) {
            b = (A * b) % n;
        }
    }
    return b;
}

bool millerRabin(ll a, ll n) {
    if (n <= 3) return true;
    ll r = n - 1;
    int s = 0;
    while (r % 2 == 0) {
        s++;
        r /= 2;
    }
    ll y = mod(a, r, n);
    if (y == 1 || y == n - 1) return true;

    for (int i = 1; i < s; i++) {
        y = (y * y) % n;
        if (y == 1) return false;
        if (y == n - 1) return true;
    }
    return false;
}

bool checkPrime(ll n) {
    if (n == 2 || n == 3) return true;
    if (n < 2 || n % 2 == 0) return false;
    for (int i = 0; i < 5; i++) {
        ll a = 2 + rand() % (n - 3);
        if (!millerRabin(a, n)) return false;
    }
    return true;
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
            ll v = uv % power(2,8);
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



int main(){
	ll A[1000], B[1000], C[1000];
    ll p, q;

    printf("Nhap so nguyen to p: ");
    scanf("%lld", &p);
    while (!checkPrime(p) && p % 4 != 3 ) {
        printf("Nhap lai so nguyen to p: ");
        scanf("%lld", &p);
    }

    printf("Nhap so nguyen to q: ");
    scanf("%lld", &q);
    while (!checkPrime(q) && q % 4 != 3) {
        printf("Nhap lai so nguyen to q: ");
        scanf("%lld", &q);
    }

    multiplyArrays(p, q, A, B, C, 4);
    ll n = convertNumber(C);
    ll m ;
    printf("Nhap thong diep can ma hoa : ");
    scanf("%lld",&m);
    ll c = mod(m,2,n);
    printf("%lld",c);

	
	
	
	return 0;
}
