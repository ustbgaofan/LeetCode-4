// Group Anagrams 
/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
*/

// Hash, time O(n), space O(n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> h;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            h[t].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& it : h) res.push_back(it.second);
        return res;
    }
};
