// Longest Substring Without Repeating Characters
/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

// Brute force, time O(n^2), space (n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N = s.size(), res = 0;
        for (int i=0; i<N; ++i) {
            unordered_set<int> h;
            for (int j=i; j<N; ++j) {
                if (!h.insert(s[j]).second) break;
            }
            res = max(res, static_cast<int>(h.size()));
        }
        return res;
    }
};

// Sliding Window, time O(n), space O(1)
// Q76, Q209
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int res = 0;
        for (int i=0, j=0, cnt=0; j<s.size(); ) {
            if (++m[s[j++]] == 2) ++cnt;
            if (cnt > 0) {
                if (--m[s[i++]] == 1) --cnt;
            }
            res = max(res, j-i);
        }
        return res;
    }
};
