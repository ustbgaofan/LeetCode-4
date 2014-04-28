// Palindrome Partitioning
/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/


// Recursive Version, benchmark for the following two versions
class Solution {
public:
    bool isPalindrome(const string &s) {
        for (int i=0, j=s.size()-1; i<j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
    
    void DFS(vector<vector<string>> &res, vector<string> &path, const string &s, int begin) {
        if (begin == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i=begin; i<s.size(); ++i) {
            string str = s.substr(begin, i-begin+1);
            if (!isPalindrome(str)) continue;
            path.push_back(str);
            DFS(res, path, s, i+1);
            path.pop_back();
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        DFS(res, path, s, 0);
        return res;
    }
};

// Recursive Version, less efficient than benchmark, due to copy
class Solution {
public:
    bool isPalindrome(const string &s) {
        for (int i=0, j=s.size()-1; i<j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
    
    vector<vector<string>> DFS(const string &s, int begin) {
        if (begin == s.size()) {
            vector<vector<string>> res(1);
            return res;
        }
        vector<vector<string>> res;
        for (int i=begin; i<s.size(); ++i) {
            string str = s.substr(begin, i-begin+1);
            if (!isPalindrome(str)) continue;
            vector<vector<string>> v = DFS(s, i+1);
            for (int j=0; j<v.size(); ++j) {
                v[j].insert(v[j].begin(), str);
                res.push_back(v[j]);
            }
        }
        return res;
    }
    
    vector<vector<string>> partition(string s) {
        return DFS(s, 0);
    }
};

// Recursive Version, more efficient than 2nd, but still less efficient than benchmark
class Solution {
public:
    bool isPalindrome(const string &s) {
        for (int i=0, j=s.size()-1; i<j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
    
    vector<vector<string> *> *DFS(const string &s, int begin) {
        if (begin == s.size()) {
            vector<vector<string> *> *res = new vector<vector<string> *>(1);
            (*res)[0] = new vector<string>;
            return res;
        }
        vector<vector<string> *> *res = new vector<vector<string> *>;
        for (int i=begin; i<s.size(); ++i) {
            string str = s.substr(begin, i-begin+1);
            if (!isPalindrome(str)) continue;
            vector<vector<string> *> *v = DFS(s, i+1);
            for (int j=0; j<v->size(); ++j) {
                (*v)[j]->insert((*v)[j]->begin(), str);
                res->push_back((*v)[j]);
            }
            delete v;
        }
        return res;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> *> *tmp = DFS(s, 0);
        vector<vector<string>> res(tmp->size());
        for (int i=0; i<res.size(); ++i) res[i] = *((*tmp)[i]);
        for (int i=0; i<tmp->size(); ++i) delete (*tmp)[i];
        delete tmp;
        return res;
    }
};

// Top-down Dynamic Programming Version, time complexity O(n^4), space complexity O(n^3)
// based on 2nd version instead of 3rd for simplicity
class Solution {
public:
    bool isPalindrome(const string &s) {
        for (int i=0, j=s.size()-1; i<j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
    
    vector<vector<string>> DFS(const string &s, int begin, vector<vector<vector<string>>> &mem) {
        if (begin == s.size()) {
            vector<vector<string>> res(1);
            return res;
        }
        if (!mem[begin].empty()) return mem[begin]; 
        for (int i=begin; i<s.size(); ++i) {
            string str = s.substr(begin, i-begin+1);
            if (!isPalindrome(str)) continue;
            vector<vector<string>> v = DFS(s, i+1, mem);
            for (int j=0; j<v.size(); ++j) {
                v[j].insert(v[j].begin(), str);
                mem[begin].push_back(v[j]);
            }
        }
        return mem[begin];
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<vector<string>>> mem(s.size());
        return DFS(s, 0, mem);
    }
};

// Bottom-up Dynamic Programming Version, time complexity O(n^4), space complexity O(n^3)
// based on 2nd version instead of 3rd for simplicity
class Solution {
public:
    bool isPalindrome(const string &s) {
        for (int i=0, j=s.size()-1; i<j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        int N = s.size();
        vector<vector<vector<string>>> mem(N);
        mem.back().push_back(vector<string>(1, s.substr(N-1, 1)));
        for (int i=N-2; i>=0; --i) {
            for (int j=i; j<N; ++j) {
                string str = s.substr(i, j-i+1);
                if (!isPalindrome(str)) continue;
                if (j+1 < N) {
                    for (int k=0; k<mem[j+1].size(); ++k) {
                        mem[i].push_back(mem[j+1][k]);
                        mem[i].back().insert(mem[i].back().begin(), str);
                    }
                } else {
                    mem[i].push_back(vector<string>(1, str));
                }
            }
        }
        return mem[0];
    }
};