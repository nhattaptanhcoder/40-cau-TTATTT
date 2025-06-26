#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
typedef long long ll;

int binary(int k , int arr[]){
	int i = 0;
	while (k != 0){
		arr[i++] = k % 2;
		k = k / 2;
	}
	return i;
}

int mod(int a, int n){
	int arr[1000];
	int length = binary(n-1,arr);
	int b = 1;
	int A = a;
	if (arr[0] == 1){
		b = a;
	}
	for (int i = 1 ; i < length ; i++){
		A = ( A * A ) % n;
		if ( arr[i] == 1){
			b = ( A * b) % n;
		}
	}
	return b;
}


bool checkFermat(int n){
	if ( n == 2 || n == 3 ){
		return true;
	}
	if ( n < 2 || n % 2 == 0){
		return false;
	}
	
	for ( int i = 0 ; i < 4 ; i++){
	    int a = 2 + rand() % ( n - 3);
	    if (mod(a,n) != 1){
	    	return false;
		}
	}
	return true;
}


int main(){
	srand(time(NULL));
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	int sum = 0;
	for ( int i = a ; i <= b ; i++){
		if (checkFermat(i)) {
			sum += i;
		}
	}
	printf("%d",sum);
	return 0;
}
