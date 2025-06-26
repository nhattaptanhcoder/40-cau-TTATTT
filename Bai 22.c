#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int assign(char P[], int L[]){
	int m = strlen(P);
	for ( int i = 0 ; i < 256 ; i++){
		L[i] = -1;
	}
	for ( int i = 0 ; i < m ; i++){
		L[(int)P[i]] = i;
	}
	return m ;
}

int min(int a , int b){
	if( a < b) {
		return a;
	}
	return b;	
}


int booyerMoore(char P[], char T[], int arr[]){
	int count = 0;
	int L[256];
	int m = assign(P,L);
	int n = strlen(T);
	int i =  m - 1;
	int j = m - 1;
	while( i < n){
		if( T[i] == P[j]){
			if( j == 0){
				arr[count++] = i+1;
				i = i + m ;
				j = m - 1;
			}
			i--;
			j--;
		}
		else{
			i = i + m - min(j, 1 + L[(int)T[i]]) ;
			j = m - 1;
		}
	}
    return count;
}


int main(){
	char text[10000];
	char pattern[1000000];
	fgets(text,sizeof(text),stdin);
	fgets(pattern,sizeof(pattern),stdin);
	text[strcspn(text, "\n")] = 0;
    pattern[strcspn(pattern, "\n")] = 0;
	int arr[1000];
	int length = booyerMoore(pattern,text,arr);
	if ( length == 0){
		printf("-1");
	}
	else{
      for ( int i = 0 ; i < length ; i++)
	  {
		printf("%d ",arr[i]);
	  }
			
  }
	
	
	return 0;
}

