#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;

int binary(ll k , int arr[]){
	int i = 0;
	while ( k != 0){
		arr[i++] = k % 2;
		k /= 2;
	}
	return i;
}

ll mod (ll a, ll k , ll n){
    int arr[1000];
    int length = binary(k,arr);
    ll b = 1;
    ll A = a;
    if ( arr[0] == 1){
    	b = a;
	}
	for ( int i = 1 ; i < length ; i++){
		A = (A * A) % n;
		if ( arr[i] == 1){
			b = ( A * b) % n;
		}
	}
	return b ;
}

bool millerRabin(ll a, ll n){
	ll r =  n - 1;
	int s = 0;
	while ( r % 2 == 0){
		s++;
		r /= 2;
	}
	ll y = mod(a,r,n);
	if ( y == 1 || y == n - 1) return true;
	for ( int i = 1 ; i < s ; i++){
		y = (y * y) % n;
		if (y == 1) return false;
		if( y == n - 1) return true;
	}
	return false;
	
}
  
bool checkPrime(ll n) {
    if (n == 2 || n == 3) return true;
    if (n < 2 || n % 2 == 0) return false;

    for (int i = 0; i < 5; i++) {
        ll a = 2 + rand() % (n - 3);
        if (!millerRabin(a,n)) return false;
    }
    return true;
}
int locso(ll arr[], ll arrSave[], int n){
	int mark[1000000] = {0};
	int count = 0;
	for ( int i = 0 ; i < n ; i++){
		ll result = arr[i];
		if ( checkPrime(result) && !mark[result]){
			arrSave[count++] = result;
			mark[result] = 1;
		}
	}
	return count ;
}

int main(){
	srand(time(NULL)); 

    int n;
    scanf("%d", &n);
    ll arr[n];
    ll arrSave[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    int length = locso(arr, arrSave, n);
    for (int i = 0; i < length; i++) {
        printf("%lld ", arrSave[i]);
    }
    return 0;
}
