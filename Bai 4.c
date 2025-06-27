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



int main(){
	ll p, g, a, b;
	printf("Nhap so nguyen to p :");
	scanf("%lld",&p);
	while (!checkPrime(p)) {
        printf("Nhap lai so nguyen to p: ");
        scanf("%lld", &p);
    }
   printf("Nhap so nguyen to g :");
   scanf("%lld",&g);
   while (!checkPrime(g)) {
        printf("Nhap lai so nguyen to g: ");
        scanf("%lld", &g);
    }
	printf("Nhap so a : ");
	scanf("%lld",&a);
	printf("Nhap so b : ");
	scanf("%lld",&b);
	
	ll A = mod(g,a,p);
	ll B = mod(g,b,p);
	ll k1 = mod(A,b,p);
	ll k2 = mod(B,a,p);
	if ( k1 == k2){
		printf("%lld",k1);
	}
	else{
		printf("Khong co khoa chung hehe");
	}
	
	
	
	
	
	return 0;
}
