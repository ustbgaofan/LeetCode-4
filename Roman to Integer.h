// Roman to Integer
/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

// time O(n), space O(1)
class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) return 0;
        unordered_map<char, int> h;
        h['I'] = 1;
        h['V'] = 5;
        h['X'] = 10;
        h['L'] = 50;
        h['C'] = 100;
        h['D'] = 500;
        h['M'] = 1000;
        int N = s.size(), res = h[s.back()];
        for (int i=N-2; i>=0; --i) res += h[s[i]]<h[s[i+1]]? -h[s[i]]: h[s[i]];
        return res;
    }
};
