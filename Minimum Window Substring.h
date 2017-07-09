// Minimum Window Substring
/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/


// Sliding Window + Counting, time O(n), space O(1)
// Q3
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (char c : t) ++m[c];
        string res;
        for (int i=0, j=0, cnt=t.size(); j<s.size(); ) {
            if (--m[s[j++]] >= 0) --cnt;
            while (cnt == 0) {
                if (res.empty() || j-i<res.size()) res = s.substr(i, j-i);
                if (++m[s[i++]] == 1) ++cnt;
            }
        }
        return res;
    }
};
