// Reverse Words in a String 
/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

// time O(n), space O(n)
class Solution {
public:
    void reverseWords(string &s) {
        istringstream in(s);
        s = "";
        string word;
        while (in >> word) {
            reverse(word.begin(), word.end());
            s += word + " ";
        }
        if (!s.empty()) s.pop_back();
        reverse(s.begin(), s.end());
    }
};

// time O(n), space O(1)
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int k = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == ' ') continue;
            if (k != 0) s[k++] = ' ';
            int j = i;
            for (; j<s.size() && s[j]!=' '; ++j) s[k++] = s[j];
            reverse(s.begin()+k-(j-i), s.begin()+k);
            i = j;
        }
        s.erase(s.begin()+k, s.end());
    }
};
