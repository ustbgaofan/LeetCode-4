// Longest Common Prefix
/*
Write a function to find the longest common prefix string amongst an array of strings.
*/


// Version 1, increasingly reduce the first string
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        if (!strs.empty()) prefix = strs[0];
        int size = strs.size();
        for (int i=1; i<size; ++i) {
            int j = 0, preSize = prefix.size(), strSize = strs[i].size();
            while (j<min(preSize,strSize) && prefix[j]==strs[i][j]) ++j;
            prefix.resize(j);
        }
        return prefix;
    }
};

// Version 2, check every char in the first string
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        if (strs.empty()) return prefix;
        int len = strs[0].size(), num = strs.size();
        for (int i=0; i<len; ++i) {
            for (int j=1; j<num; ++j)
                if (strs[j].size()<i+1 || strs[j][i]!=strs[0][i]) return prefix;
            prefix.push_back(strs[0][i]);
        }
        return prefix;
    }
};