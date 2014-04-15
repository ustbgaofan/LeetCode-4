// Minimum Window Substring
/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/


// Sliding Window + Counting
class Solution {
public:
    string minWindow(string S, string T) {
        int N = S.size(), M = T.size();
        vector<int> need(256, 0), find(256, 0);
        for (int i=0; i<M; ++i) ++need[T[i]];
        int start = -1, end = N;
        for (int i=0, j=0, count=0; j<N; ++j) {
            if (need[S[j]] == 0) continue;
            if (find[S[j]]++ < need[S[j]]) ++count;
            if (count != M) continue;
            for (; i<=j; ++i) {
                if (need[S[i]] == 0) continue;
                if (find[S[i]] == need[S[i]]) break;
                --find[S[i]];
            }
            if (j-i < end-start) {
                start = i; 
                end = j;
            }
        }
        return start==-1? "": S.substr(start, end-start+1);
    }
};