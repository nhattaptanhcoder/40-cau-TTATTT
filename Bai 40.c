#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int assign(char P[], int L[]){
	int m = strlen(P);
	for (int i = 0 ; i < 256 ; i ++){
		L[i] = -1;
	}
	for (int i = 0 ; i < m ; i++){
		L[(int)P[i]] = i;
	}
	return m;
}

int min(int a , int b){
	if ( a < b){
		return a;
	}
	return b;
}
bool booyerMoore(char P[],char T[]){
	int L[256];
	int m = assign(P,L);
	int n = strlen(T);
	int i = m - 1;
	int j = m - 1;
	while( i < n){
		if( T[i] == P[j]){
			if( j == 0){
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
	int N;
    scanf("%d", &N);
    getchar(); 

    char words[N][101]; 
    for (int i = 0; i < N; i++) {
        fgets(words[i], sizeof(words[i]), stdin);
        int len = strlen(words[i]);
        if (words[i][len - 1] == '\n') {
            words[i][len - 1] = '\0';
        }
    }
    bool found = false;
    for (int i = 0 ; i < N ; i++){
    	for ( int j = 0 ; j < N ; j++){
    		if (strlen(words[i]) > strlen(words[j]) || i == j){
    			continue;
			}
			if(booyerMoore(words[i],words[j])){
				printf("%s ",words[i]);
				found = true ;
				break;
			}
		}
	}
    if ( !found ){
    	printf("None");
	}
	return 0;
}
