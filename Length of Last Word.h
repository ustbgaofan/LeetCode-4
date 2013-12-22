// Length of Last Word
/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

// Version 1
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int end = strlen(s) - 1;
        while (end>=0 && s[end]==' ') --end;
        int start = end;
        while (start>=0 && s[start]!=' ') --start;
        return end - start;
    }
};

// Version 2
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s), res = 0;
        for (int i=len-1; i>=0; --i)
            if (s[i] != ' ') ++res;
            else if (res > 0) break;
        return res;
    }
};