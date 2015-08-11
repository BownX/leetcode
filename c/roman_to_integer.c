/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

https://leetcode.com/problems/roman-to-integer/
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int val(char c) {
    switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    }
    return 0;
}

/*
从后往前扫，记录前一个不同的字符pre，当前字符和pre比较来确定当前值的加减
*/
int romanToInt(char* s) {
    int result = 0;
    int length = strlen(s);
    char pre = ' ';
    char cur = ' ';
    for (int i = length - 1; i >= 0; --i) {
        if (s[i] != cur) {
            pre = cur;
        }
        cur = s[i];
        if (val(pre) != 0) {
            if (val(pre) > val(cur)) {
                result -= val(cur);
            } else {
                result += val(cur);
            }
        } else {
            result += val(s[i]);
        }
    }
    return result;
}

int main(int argc, char const *argv[]) {
    char s[20];
    while (1) {
        scanf("%s", s);
        printf("%d\n", romanToInt(s));
    }
    return 0;
}