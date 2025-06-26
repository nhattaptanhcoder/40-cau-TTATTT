#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;


int convertBinary(int arr[], int k){
	int i = 0;
	while (k > 0){
		arr[i++] = k % 2;
		k = k / 2;
	}
	return i;
}

int mod(int a, int k , int n){
	int arr[1000];
	int b = 1;
	int length = convertBinary(arr, k);
	int A = a;
	if (arr[0] == 1){
		b = a;
	}
	for (int i = 1; i < length; i++){
		A = (A * A) % n;
		if (arr[i] == 1){
			b = (A * b) % n;
		}
	}
	return b;
}


int milerRabin(int n , int a){
	
	int s = 0;
	int r = n - 1;
	while ( r % 2 == 0){
		s ++;
		r /= 2;
	}
	int y = mod(a ,r ,n);
	if ( y == 1 || y == n-1) return 1 ;
	for ( int i = 1 ; i < s; i++){
		y = ( y * y ) % n;
		if ( y == 1 ) return 0;
		if ( y == n - 1)  return 1;
	}
	return 0;	
}

bool checkPrime ( int n ){
    if( n == 2 || n == 3 ) return 1;
	if ( n < 2 || n % 2 == 0 ) return 0;
	for ( int i = 0 ; i < 5 ; i++){   
	    ll a = 2 + rand() % ( n-3);
		if (!milerRabin(n,a)) return false;
	}
	return true;
}



int main(){
	srand(time(NULL));
	int a;
	scanf("%d",&a);
	int b;
	scanf("%d",&b);
	int sum = 0;
	for (int i = a ; i <= b ; i++){
		if(checkPrime(i)) {
			sum += i;
		} 
	}
	printf("%d",sum);
	
}
