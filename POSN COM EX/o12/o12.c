#include <iostream>

int checkPalindrome(char *s, int l, int r) {
    if (l >= r) {
        return 1;
    } else {
        if (s[l] == s[r]) {
            return checkPalindrome(s, l+1, r-1);
        } else {
            return 0;
        }
    }
}


int main() {
    char s[100];
    gets(s);
    int len = strlen(s);
    if (s[0] == s[len-1]) {
        printf("%d", checkPalindrome(s, 1, len-2));
    } else {
        printf("0");
    }
}