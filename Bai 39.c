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
		L[(int)P[i]] = i ;
	}
	return m ;
}

int min( int a , int b){
	if ( a < b){
		return a;
	}
	return b;
}
int booyerMoore(char P[], char T[]){
	int L[256];
	int m = assign(P,L);
	int n = strlen(T);
	int i = m - 1;
	int j = n - 1;
	while ( i < n){
		if ( T[i] == P[j]){
			if ( j == 0){
				return i;
			}
			i--;
			j--;
		}
		else{
			i = i + m - min(j,1+L[(int)T[i]]);
			j = m - 1;
			
		}
	}
	return -1;
}


int main(){
	char sentence[1001];
	char searchWord[1001];
	fgets(sentence,sizeof(sentence),stdin);
	int len = strlen(sentence);
	if (sentence[len - 1] == '\n') sentence[len - 1] = '\0';
	fgets(searchWord,sizeof(searchWord),stdin);
	len = strlen(searchWord);
	if (searchWord[len - 1] == '\n') searchWord[len - 1] = '\0';
	char *token = strtok(sentence," ");
	int index = 1;
	int found = 0;
	while( token != NULL ){
		int result = booyerMoore(searchWord,token);
		if(result == 0){
			printf("%d",index);
			found = 1;
			break;
		}
		index++;
		token = strtok(NULL," ");
	}
	if (!found){
		printf("-1");
	}

	return 0;
}
