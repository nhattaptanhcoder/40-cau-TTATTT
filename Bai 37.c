#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int assign(char P[], int L[]) {
    int m = strlen(P);
    for (int i = 0; i < 256; i++) {
        L[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        L[(int)P[i]] = i;
    }
    return m;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

bool booyerMoore(char P[], char T[]) {
    int L[256];
    int m = assign(P, L);
    int n = strlen(T);
    int i = m - 1;
    int j = m - 1;
    while (i < n) {
        if (T[i] == P[j]) {
            if (j == 0) return true;
            i--;
            j--;
        } else {
            i = i + m - min(j, 1 + L[(int)T[i]]);
            j = m - 1;
        }
    }
    return false;
}

bool check(char s[], char goal[]) {
    int n = strlen(s);
    char temp[1001] = "";
    if (n != strlen(goal)) return false;
    for (int i = 0; i < n; i++) {
        strcpy(temp, s + i);
        strncat(temp, s, i);
        temp[n] = '\0';  
        if (booyerMoore(temp, goal)) return true;
    }
    return false;
}

int main() {
    char s[1001];
    char goal[1001];

    fgets(s, sizeof(s), stdin);
    if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';

    fgets(goal, sizeof(goal), stdin);
    int len = strlen(goal);
    if (goal[len - 1] == '\n') goal[len - 1] = '\0';

    if (check(s, goal)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}

