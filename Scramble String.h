// Scramble String
/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/


// 1st Version with Duplicate Calculation 
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        /*string t1 = s1, t2 = s2; 
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) return false;*/
        int N = s1.size();
        vector<int> count(26, 0);
        for (int i=0; i<N; ++i) ++count[s1[i]-'a'], --count[s2[i]-'a'];
        for (int i=0; i<26; ++i) {
            if (count[i] != 0) return false; 
        }
        for (int i=1; i<N; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i), s2.substr(i)) ||
                isScramble(s1.substr(0, i), s2.substr(N-i)) && 
                isScramble(s1.substr(i), s2.substr(0, N-i)))
                return true;
        }
        return false;
    }
};

// Top-down Dynamic Programming Version, time complexity O(n^3), space complexity O(n^3)
class Solution {
public:
    bool isScramble(const string &s1, int i, const string &s2, int j, int n, vector<vector<vector<int>>> &mem) {
        if (mem[i][j][n-1] != -1) return mem[i][j][n-1];
        if (s1.substr(i, n) == s2.substr(j, n)) return mem[i][j][n-1] = true;
        vector<int> count(26, 0);
        for (int k=0; k<n; ++k) ++count[s1[i+k]-'a'], --count[s2[j+k]-'a'];
        for (int k=0; k<26; ++k) {
            if (count[k] != 0) return false; 
        }
        for (int l=1; l<n; ++l) {
            if (isScramble(s1, i, s2, j, l, mem) && isScramble(s1, i+l, s2, j+l, n-l, mem) ||
                isScramble(s1, i, s2, j+n-l, l, mem) && isScramble(s1, i+l, s2, j, n-l, mem))
                return mem[i][j][n-1] = true;
        }
        return mem[i][j][n-1] = false;
    }
    
    bool isScramble(string s1, string s2) {
        int N = s1.size();
        vector<vector<vector<int>>> mem(N, vector<vector<int>>(N, vector<int>(N, -1)));
        return isScramble(s1, 0, s2, 0, N, mem);
    }
};

// Bottom-up Dynamic Programming Version, time complexity O(n^3), space complexity O(n^3)
class Solution {
public:
    bool isScramble(string & s1, string & s2) {
        int N = s1.size();
        vector<vector<vector<bool>>> mem(N, vector<vector<bool>>(N, vector<bool>(N, false)));
        for (int l=1; l<=N; ++l) {
            for (int i=0; i<=N-l; ++i) {
                for (int j=0; j<=N-l; ++j) {
                    if (l == 1) {
                        if (s1[i] == s2[j]) mem[i][j][l-1] = true;
                        continue;
                    }
                    for (int k=1; k<l; ++k) {
                        if (mem[i][j][k-1] && mem[i+k][j+k][l-k-1] ||
                            mem[i][j+l-k][k-1] && mem[i+k][j][l-k-1])
                            mem[i][j][l-1] = true;
                    }
                }
            }
        }
        return mem[0][0][N-1];
    }
};