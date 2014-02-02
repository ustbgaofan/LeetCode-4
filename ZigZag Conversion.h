// ZigZag Conversion
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

/***************
EXAMPLE 1:
0     6     12
1   5 7   11 *
2 4   8 10   *
3     9      *

EXAMPLE 2:
0 1 2 3

EXAMPLE 3:
0 2 4
1 3 5
***************/

class Solution {
public:
    string convert(string s, int nRows) {
		if (nRows == 1) return s;
		string res;
		int size = s.size();
		for (int i=0; i<nRows; ++i) {
			for (int j=i; j<size; j+=2*nRows-2) {
				res += s[j];
				int pos = j + 2*nRows - 2*i -2;
				if (i!=0 && i!=nRows-1 && pos<size) 
					res += s[pos];
			}
		}
		return res;
    }
};