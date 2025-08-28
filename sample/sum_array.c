#include "minicio.h"

int n;
int arr[100];
int sum;

void calculateSum() {
    int i;
    sum = 0;
    for (i = 0; i < n; i = i + 1) {
        sum = sum + arr[i];
    }
}

int main() {
    int i;
    n = getint();
    for (i = 0; i < n; i = i + 1) {
        arr[i] = getint();
    }
    calculateSum();
    putint(sum);
    putnewline();
    return 0;
}