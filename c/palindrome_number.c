#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int record[32];
    int length = 0;
    int temp = x;
    while (temp != 0) {
        record[length] = temp % 10;
        temp = temp / 10;
        length++;
    }
    for (int i = 0; i < length / 2; ++i) {
        if (record[i] != record[length - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    printf("%d \n", isPalindrome(12321));
    return 0;
}