#include "minicio.h"

int n;
int arr[100];
int isPalindrome;

void checkPalindrome() {
    int i;
    isPalindrome = 1;
    for (i = 0; i < n / 2; i = i + 1) {
        if (arr[i] != arr[n - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }
}

int main() {
    int i;
    n = getint();
    for (i = 0; i < n; i = i + 1) {
        arr[i] = getint();
    }
    checkPalindrome();
    if (isPalindrome == 1) {
        putint(1);
    } else {
        putint(0);
    }
    putnewline();
    return 0;
}