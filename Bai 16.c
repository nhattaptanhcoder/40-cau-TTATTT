#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef long long ll;


int binary(ll k , int arr[]){
	int i = 0;
	while (k != 0){
		arr[i++] = k % 2;
		k = k / 2;
	}
	return i;
}


ll mod(ll a,ll k, ll n) {
	int arr[1000];
	int length = binary(k,arr);
	ll b = 1;
	ll A = a;
	if ( arr[0] == 1){
		b = a;
	}
	for ( int i = 1 ; i < length ; i++){
		A = ( A * A ) % n;
		if ( arr[i] == 1){
			b = ( A * b) % n;
		}
	}
	return b;
}

void checkPrime(int t, ll a[],ll n){
	for ( int i = 0 ; i < t ; i++){
		if(mod(a[i],n-1,n) != 1){
			printf("%d\n",i+1);
			return;
		}
	}
	printf("-1\n");
}


int main() {
	ll n, a[1000];
	int t;

	scanf("%lld",&n);
	scanf("%d", &t);
    
    for ( int i = 0 ; i < t ; i++){
    	scanf("%lld",&a[i]);
	}
	checkPrime(t,a,n);
	return 0;
}

