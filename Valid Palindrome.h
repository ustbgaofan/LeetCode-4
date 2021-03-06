// Valid Palindrome
/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

// time O(n), space O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i<j && !isalnum(s[i])) ++i;
            while (j>i && !isalnum(s[j])) --j;
            if (i<j && tolower(s[i++])!=tolower(s[j--])) return false;
        }
        return true;
    }
};
