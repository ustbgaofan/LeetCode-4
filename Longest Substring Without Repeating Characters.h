// Longest Substring Without Repeating Characters
/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool visited[256] = {false};
        int maxLen = 0, size = s.size();
        for (int i=0, j=0; i<size, j<size; ++i) {
            while (j<size && !visited[s[j]]) visited[s[j++]] = true;
            maxLen = max(j-i, maxLen);
            visited[s[i]] = false;
        }
        return maxLen;
    }
};