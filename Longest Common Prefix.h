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

// Recursive Version, O(n)=2O(n/2)+m--->O(nm) same as above methods
class Solution {
public:
    string longestCommonPrefix(string str1, string str2) {
        int size = min(str1.size(), str2.size());
        for (int i=0; i<size; ++i) {
            if (str1[i] != str2[i]) return str1.substr(0, i);
        }
        return str1.substr(0, size);
    }
    
    string longestCommonPrefix(vector<string> &strs, int begin, int end) {
        if (begin > end) return "";
        if (begin == end) return strs[begin];
        int mid = (begin + end)/2;
        return longestCommonPrefix(longestCommonPrefix(strs, begin, mid),
                                   longestCommonPrefix(strs, mid+1, end));
    }
    
    string longestCommonPrefix(vector<string> &strs) {
        return longestCommonPrefix(strs, 0, strs.size()-1);
    }
};