/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

https://leetcode.com/problems/zigzag-conversion/
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char* convert(char* s, int numRows) {
	if (numRows <= 1) {
		return s;
	}
    int length = strlen(s);
    int row_of_char[length];
    int current_row = 0;
    int direction = 1;
    for (int i = 0; i < length; ++i) {
    	row_of_char[i] = current_row;
    	if (current_row == 0) {
    		direction = 1;
    	}
    	if (current_row == numRows - 1) {
    		direction = -1;
    	}
    	current_row += direction;
    }
    char* result = malloc(sizeof(char) * (length + 1));
    int index = 0;
    for (int i = 0; i < numRows; ++i) {
    	for (int j = 0; j < length; ++j) {
    		if (row_of_char[j] == i) {
    			result[index] = s[j];
    			index++;
    		}
    	}
    }
    result[length] = '\0';
    return result;
}

int main(int argc, char const *argv[]) {
	printf("%s\n", convert("AB", 1));
	return 0;
}