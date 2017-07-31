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


// Recursive Version, Time Limit Exceeded 
class Solution {
public:
    int numDecodings(string &s, int begin) {
        if (begin == s.size()) return 1;
        int count = 0;
        if (s[begin]>='1' && s[begin]<='9') 
            count += numDecodings(s, begin+1);
        if (begin+1<s.size() && s[begin]=='1' && s[begin+1]>='0'&& s[begin+1]<='9') 
            count += numDecodings(s, begin+2); 
        if (begin+1<s.size() && s[begin]=='2' && s[begin+1]>='0'&& s[begin+1]<='6') 
            count += numDecodings(s, begin+2);
        return count;
    }
    
    int numDecodings(string s) {
        if (s.empty()) return 0;
        return numDecodings(s, 0);
    }
};

// Top-down Dynamic Programming, time O(n), space O(n)
class Solution {
public:
    int numDecodings(string &s, int begin, vector<int> &mem) {
        if (begin<s.size() && mem[begin] != -1) return mem[begin];
        if (begin == s.size()) return 1;
        mem[begin] = 0;
        if (s[begin]>='1' && s[begin]<='9') 
            mem[begin] += numDecodings(s, begin+1, mem);
        if (begin+1<s.size() && s[begin]=='1' && s[begin+1]>='0'&& s[begin+1]<='9') 
            mem[begin] += numDecodings(s, begin+2, mem); 
        if (begin+1<s.size() && s[begin]=='2' && s[begin+1]>='0'&& s[begin+1]<='6') 
            mem[begin] += numDecodings(s, begin+2, mem);
        return mem[begin];
    }
    
    int numDecodings(string s) {
        if (s.empty()) return 0;
        vector<int> mem(s.size(), -1);
        return numDecodings(s, 0, mem);
    }
};

// Bottom-up Dynamic Programming, time O(n), space O(n)
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int size = s.size();
        vector<int> mem(size, 0);
        if (s.back()>='1' && s.back()<='9') mem.back() = 1;
        if (size>1 && s[size-2]>='1' && s[size-2]<='9') mem[size-2] = mem.back();
        if (size>1 && s[size-2]=='1' && s.back()>='0'&& s.back()<='9') ++mem[size-2];
        if (size>1 && s[size-2]=='2' && s.back()>='0'&& s.back()<='6') ++mem[size-2];
        for (int i=size-3; i>=0; --i) {
            if (s[i]>='1' && s[i]<='9') mem[i] += mem[i+1];
            if (s[i]=='1' && s[i+1]>='0'&& s[i+1]<='9') mem[i] += mem[i+2];
            if (s[i]=='2' && s[i+1]>='0'&& s[i+1]<='6') mem[i] += mem[i+2];
        }
        return mem[0];
    }
};

// Space Optimized Bottom-up Dynamic Programming time O(n), space O(1) 
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int size = s.size();
        vector<int> mem(2, 0);
        if (s.back()>='1' && s.back()<='9') mem[(size-1)%2] = 1;
        if (size>1 && s[size-2]>='1' && s[size-2]<='9') mem[(size-2)%2] = mem[(size-1)%2];
        if (size>1 && s[size-2]=='1' && s.back()>='0'&& s.back()<='9') ++mem[(size-2)%2];
        if (size>1 && s[size-2]=='2' && s.back()>='0'&& s.back()<='6') ++mem[(size-2)%2];
        for (int i=size-3; i>=0; --i) {
            if (s[i]=='1' && s[i+1]>='0'&& s[i+1]<='9' ||
                s[i]=='2' && s[i+1]>='0'&& s[i+1]<='6') ;
            else mem[(i+2)%2] = 0;
            if (s[i]>='1' && s[i]<='9') mem[(i+2)%2] += mem[(i+1)%2];
        }
        return mem[0];
    }
};
