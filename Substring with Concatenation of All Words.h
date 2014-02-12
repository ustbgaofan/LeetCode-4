// Substring with Concatenation of All Words 
/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

// Time Limit Exceeded Version, first hash, then compare
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string, int> hash;
        int num = L.size(), len = L[0].size();
        for (int i=0; i<num; ++i) ++hash[L[i]];
        vector<int> res;
		int size1 = (int)S.size() - num*len;  // must convert from size_t to int
        for (int i=0; i<=size1; ++i) {
            unordered_map<string, int> tmpHash;
            int size2 = i + num*len;
            for (int j=i; j<size2; j+=len) 
                ++tmpHash[S.substr(j, len)];
            if (tmpHash == hash) res.push_back(i);
        }
        return res;
    }
};

// Advanced Version, hash with filtering
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string, int> hash;
        int num = L.size(), len = L[0].size();
        for (int i=0; i<num; ++i) ++hash[L[i]];
        vector<int> res;
        int size1 = (int)S.size() - num*len;  // must convert from size_t to int
        for (int i=0; i<=size1; ++i) {
            unordered_map<string, int> tmpHash;
            int j = i;
            int size2 = i + num*len;
            for (; j<size2; j+=len) {
                string str = S.substr(j, len);
                if (hash.find(str) == hash.end()) break;
                ++tmpHash[str];
                if (tmpHash[str] > hash[str]) break;
            }
            if (j == size2) res.push_back(i);
        }
        return res;
    }
};