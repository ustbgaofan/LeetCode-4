// Reverse Words in a String 
/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/


// All-->Part, time complexity O(n), space complexity O(n)
class Solution {
public:
    void reverseWords(string &s) {
        string t;
        bool space = false;
        for (int i=s.size()-1; i>=0; --i) {
            if (s[i] == ' ') {
                space = true;
                continue;
            }
            if (space && !t.empty()) t += " ";
            space = false;
            t += s[i];
        }
        for (int i=0; i<t.size(); ++i) {
            int j = i;
            for (; j<t.size() && t[j]!=' '; ++j);
            reverse(t.begin()+i, t.begin()+j);
            i = j; 
        }
        s = t;
    }
};