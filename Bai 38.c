#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int assign(char P[], int L[]){
	int m = strlen(P);
	for ( int i = 0 ; i < 256 ; i++){
		L[i] = -1;
	}
	for ( int i = 0 ; i < m ; i++){
		L[(int)P[i]] = i;
	}
	return m;	
}

int min(int a , int b){
	if( a < b){
		return a;
	}
	return b;
}

bool booyerMoore(char P[], char T[]){
	int L[256];
	int m = assign(P,L);
	int n = strlen(T);
	int i = m - 1;
	int j = m - 1;
	while( i < n){
		if (T[i] == P[j] ){
			if ( j == 0){
				return true;
			}
			i--;
			j--;
		}
		else{
			i = i + m - min(j,1+L[(int)T[i]]);
			j = m - 1;
		}
	}
	return false;
}

int main(){
	char sequence[1001];
	char word[1001];
	fgets(sequence,sizeof(sequence),stdin);
	int len = strlen(sequence);
	if(sequence[len - 1] == '\n') sequence[len - 1] = '\0';
	fgets(word,sizeof(word),stdin);
	len = strlen(word);
	if ( word[len - 1] == '\n' ) word[len - 1]= '\0';
	char temp[1001]= "";
    int count = 0;
    int max = 0;
    while(strlen(word) + strlen(temp) <= strlen(sequence)){
    	strcat(temp,word);
    	count++;
    	if (booyerMoore(temp,sequence)){
    		max = count;
		}
	}
	printf("%d",max);
	
	return 0;
}
