// Longest Substring Without Repeating Characters
/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

// Sliding Window + Counting, time O(n), space O(1)
// Q76
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int res = 0;
        for (int i=0, j=0, cnt=0; j<s.size(); ) {
            if (++m[s[j++]] == 2) ++cnt;
            while (cnt > 0) {
                if (--m[s[i++]] == 1) --cnt;
            }
            res = max(res, j-i);
        }
        return res;
    }
};
