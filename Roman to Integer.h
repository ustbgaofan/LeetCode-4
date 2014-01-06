// Roman to Integer
/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/


class Solution {
public:
    int romanToInt(string s) {
        if (!s.size()) return 0;
        unordered_map<char, int> hash;
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;
        int size = s.size(), res = hash[s[size-1]];
        for (int i=size-2; i>=0; --i) {
            if (hash[s[i]] >= hash[s[i+1]]) res += hash[s[i]]; 
            else res -= hash[s[i]];
        }
        return res;
    }
};