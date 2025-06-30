#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;

ll power(int a , int b){
	ll res = 1;
	for ( int i = 0 ; i < b ; i++){
		res *= a;
	}
	return res;
}

int convertBinary(ll k , int arr[]){
	int i = 0 ;
	while( k != 0){
		arr[i++] = k % 2;
		k /= 2;
	}
	return i ;
}

ll mod(ll a, ll k , ll n){
	int arr[1000];
	int m = convertBinary(k,arr);
	ll b = 1 ;
	ll A = a;
	if(arr[0] == 1){
		b = a;
	}
	for ( int i = 1 ; i < m; i++){
		A = ( A * A) % n;
		if ( arr[i] == 1){
			b = ( A * b) % n;
		}
	}
	return b;
}

void convertArray(ll a , ll A[], ll t){
	for ( int i = 0 ; i < t ; i++){
		A[i] = a % power(2,8);
		a /= power(2,8);
	}	
}

void multiplyArrays(ll a , ll b , ll A[] , ll B[], ll C[], int t){
	convertArray(a,A,t);
	convertArray(b,B,t);
	for ( int i = 0 ; i < t ; i++){
		C[i] = 0;
	}
	for ( int i = 0 ; i < t ; i++){
		ll u = 0;
		for ( int j = 0 ; j < t ; j++){
			ll uv = A[i] * B[j] + C[i+j] + u;
			C[i+j] = uv % power(2,8);
			u = uv / power(2,8);
		}
		C[i+t] = u;
	}
}

ll convertNumber(ll C[], ll t){
	ll num = 0;
	for (int i = 0 ; i < 2 * t ; i++){
		num += C[i] * power(2, i * 8);
	}
	return num;
}

bool millerRabin( ll a , ll n){
	
	ll r = n - 1;
	int s = 0;
	while ( r % 2 == 0){
		s++ ;
		r /= 2;
	}
	ll y = mod(a,r,n);
	if ( y == 1 || y == n - 1) return true;
	for ( int i = 0 ; i < s ; i++){
		y = ( y * y ) % n;
		if ( y == 1) return false;
		if ( y == n - 1) return true;
	}
	return false;
}

bool checkPrime(ll n){
	if ( n == 2 || n == 3) return true;
	if ( n < 2 || n % 2 == 0) return false;
	for ( int i = 0 ; i < 5 ; i++){
		ll a = 2 + rand() % ( n - 3);
		if (!millerRabin(a,n)) return false;
	}
	return true;
}
int main(){
	
	ll A[1000], B[1000], C[1000];
    ll p, q, m, d;

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
    ll n = convertNumber(C,4);
    printf("Nhap thong diep m :");
    scanf("%lld",&m);
    printf("Nhap khoa ky d : ");
    scanf("%lld",&d);
    ll s = mod(m,d,n);
    printf("%lld",s);
	return 0;
}
