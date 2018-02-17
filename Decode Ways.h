// Decode Ways
/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/


// Recursive Version
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        return DFS(s, 0);
    }
    
    int DFS(const string& s, int i) {
        if (i == s.size()) return 1;
        int res = 0;
        if (s[i]>='1' && s[i]<='9') res += DFS(s, i+1);
        if (i+1<s.size() && s[i]=='1' && s[i+1]>='0' && s[i+1]<='9') res += DFS(s, i+2);
        if (i+1<s.size() && s[i]=='2' && s[i+1]>='0' && s[i+1]<='6') res += DFS(s, i+2);
        return res;
    }
};

// Top-down Dynamic Programming, time O(n), space O(n)
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        vector<int> m(s.size(), -1);
        return DFS(s, 0, m);
    }
    
    int DFS(const string& s, int i, vector<int>& m) {
        if (i == s.size()) return 1;
        if (m[i] != -1) return m[i];
        int res = 0;
        if (s[i]>='1' && s[i]<='9') res += DFS(s, i+1, m);
        if (i+1<s.size() && s[i]=='1' && s[i+1]>='0' && s[i+1]<='9') res += DFS(s, i+2, m);
        if (i+1<s.size() && s[i]=='2' && s[i+1]>='0' && s[i+1]<='6') res += DFS(s, i+2, m);
        return m[i] = res;
    }
};

// Bottom-up Dynamic Programming, time O(n), space O(n)
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int N = s.size();
        vector<int> m(N, 0);
        if (s.back()>='1' && s.back()<='9') m.back() = 1;
        if (N>1 && s[N-2]>='1' && s[N-2]<='9') m[N-2] = m.back();
        if (N>1 && s[N-2]=='1' && s.back()>='0' && s.back()<='9') ++m[N-2];
        if (N>1 && s[N-2]=='2' && s.back()>='0' && s.back()<='6') ++m[N-2];
        for (int i=N-3; i>=0; --i) {
            if (s[i]>='1' && s[i]<='9') m[i] = m[i+1];
            if (s[i]=='1' && s[i+1]>='0' && s[i+1]<='9') m[i] += m[i+2];
            if (s[i]=='2' && s[i+1]>='0' && s[i+1]<='6') m[i] += m[i+2];
        }
        return m[0];
    }
};

// Space-optimized Bottom-up Dynamic Programming, time O(n), space O(1) 
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int N = s.size();
        vector<int> m(3, 0);
        if (s.back()>='1' && s.back()<='9') m[(N-1)%3] = 1;
        if (N>1 && s[N-2]>='1' && s[N-2]<='9') m[(N-2)%3] = m[(N-1)%3];
        if (N>1 && s[N-2]=='1' && s.back()>='0' && s.back()<='9') ++m[(N-2)%3];
        if (N>1 && s[N-2]=='2' && s.back()>='0' && s.back()<='6') ++m[(N-2)%3];
        for (int i=N-3; i>=0; --i) {
            m[i%3] = (s[i]>='1' && s[i]<='9')? m[(i+1)%3]: 0;  // corner case!
            if (s[i]=='1' && s[i+1]>='0' && s[i+1]<='9') m[i%3] += m[(i+2)%3];
            if (s[i]=='2' && s[i+1]>='0' && s[i+1]<='6') m[i%3] += m[(i+2)%3];
        }
        return m[0];
    }
};
