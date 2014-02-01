// Longest Substring Without Repeating Characters
/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

// Version 1, there are unnecessary calculations about max 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool visited[256];
		memset(visited, 0, sizeof(visited));
        int maxLen = 0, size = s.size();
        for (int i=0, j=0; i<size; ++i) {
            while (j<size && !visited[s[j]]) visited[s[j++]] = true;
            maxLen = max(j-i, maxLen);  
            if (j == size) break;
            visited[s[i]] = false;
        }
        return maxLen;
    }
};

// Version 2, no unnecessary calculations about max
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool visited[256];
		memset(visited, 0, sizeof(visited));
        int maxLen = 0, size = s.size();
        for (int i=0, j=0; i<size; ++i) {
            while (j<size && !visited[s[j]]) visited[s[j++]] = true;
            maxLen = max(j-i, maxLen);
            if (j == size) break;
            while (s[i] != s[j]) visited[s[i++]] = false;
            visited[s[i]] = false;
        }
        return maxLen;
    }
};