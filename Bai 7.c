#include <stdio.h>
#include <stdlib.h>

typedef long long ll;


int convertBinary(ll k, int bin[]) {
    int i = 0;
    while (k > 0) {
        bin[i++] = k % 2;
        k /= 2;
    }
    return i;
}


ll mod(ll a, ll k, ll n) {
    int bin[1000];
    int len = convertBinary(k, bin);
    ll result = 1;
    ll A = a;

    if (bin[0] == 1) result = a;

    for (int i = 1; i < len; i++) {
        A = (A * A) % n;
        if (bin[i] == 1) {
            result = (result * A) % n;
        }
    }
    return result;
}

int main() {
    ll p, g, x;

    printf("Nhap so nguyen to p: ");
    scanf("%lld", &p);

    printf("Nhap phan tu nguyen thuy g: ");
    scanf("%lld", &g);

    printf("Nhap khoa rieng x (1 <= x <= p-2): ");
    scanf("%lld", &x);

    if (x < 1 || x > p - 2) {
        printf("Gia tri x khong hop le!\n");
        return 1;
    }

    ll y = mod(g, x, p);
    printf("Khoa cong khai y = %lld\n", y);

    return 0;
}

