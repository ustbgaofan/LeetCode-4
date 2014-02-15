// Anagrams 
/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/


// Version 1, intra string sorting, single hash value
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        unordered_map<string, int> hash;
        for (int i=0; i<strs.size(); ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (hash.find(str) == hash.end()) {
                hash[str] = i;
            } else {
                if (hash[str] >= 0) {
                    res.push_back(strs[hash[str]]);
                    hash[str] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};

// Version 2, intra string sorting, multi hash value
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<int>> hash;
        for (int i=0; i<strs.size(); ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            hash[str].push_back(i);
        }
        vector<string> res;
        unordered_map<string, vector<int>>::iterator it = hash.begin();
        for (; it!=hash.end(); ++it) {
            int size = it->second.size();
            if (size > 1) {
                for (int i=0; i<size; ++i) { 
                    res.push_back(strs[(it->second)[i]]);
                }
            }
        }
        return res;
    }
};