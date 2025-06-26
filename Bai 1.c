#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;


ll convertBinary(ll k, ll arr[]){
	int i = 0;
	while ( k > 0){
	   arr[i++] = k % 2;
	   k = k / 2;
	}
	return i;
		
}


ll mod(ll a, ll k , ll n ){
	ll arr[1000];
	int length = converBinary(k,arr);
	int b = 1;
	int A = a;
	if(arr[0] == 1){
		b = a;
	}
	for ( int i = 1 ; i < length ; i++){
		A = ( A * A ) % n;
		if ( arr[i] == 1){
			b = ( A * b ) % n;
		}
	}
  
  return b;
}


bool millerRabin(ll n, ll a){
	ll r = n - 1;
	int s = 0;
	while ( r % 2 != 0 ){
		s++;
		r = r / 2;
	}
	ll y = mod (a,r,n);
	if ( y == 1 || y == n - 1) {
	   return 1;
	   
	}
	else{
		
		for ( int i = 1 ; i < s ; i ++){
		   y = ( y * y ) % n;
		   if ( y == 1) return 0;
		   if ( y == n - 1) return 1;
	   }
	return 0;
		
	}
	
}


bool checkPrime(ll n){
	if ( n == 2 || n == 3)  return 1;
	if ( n < 2 || n % 2 == 0) return 0;
	for ( int i = 1 ; i <= 5 ; i++){
		ll a = 2 + rand( n - 3 );
		if(!millerRabin(n,a)) return 0;
	} 
	return 1;
}

ll gcd( ll a, ll b){
	ll r ;
	while( b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return b;
}



int main(){
    ll p;
    printf("Nhap so nguyen to p :");
    scanf("%lld",&p);
    while(!checkPrime(p)){
    	printf("Nhap lai so nguyen to p :");
    	scanf("%lld",&p);
	}
	ll q;
    printf("Nhap so nguyen to q :");
    scanf("%lld",&q);
    while(!checkPrime(q)){
    	printf("Nhap lai so nguyen to q :");
    	scanf("%lld",&q);
	}
    ll e;
    printf("Nhap so nguyen e :");
    scanf("%lld",&e);
	
	
	
	return 0;
	
}
