// Integer to Roman
/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

// Version 1, unordered_map could not be used, because its keys are unordered.
// Keys in map are ordered, whose underlying is red-black tree. 
class Solution {
public:
    string intToRoman(int num) {
        map<int, string> hash;
        hash[1000] = "M";
        hash[900] = "CM";
        hash[500] = "D";
        hash[400] = "CD";
        hash[100] = "C";
        hash[90] = "XC";
        hash[50] = "L";
        hash[40] = "XL";
        hash[10] = "X";
        hash[9] = "IX";
        hash[5] = "V";
        hash[4] = "IV";
        hash[1] = "I";
        string res;
        for (map<int, string>::reverse_iterator it=hash.rbegin(); it!=hash.rend() && num>0; ++it) {
            while (num >= it->first) {
                res += it->second;
                num -= it->first;
            }
        }
        return res;
    }
};

// Version 2, two arrays form a hash
class Solution {
public:
    string intToRoman(int num) {
        int keys[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string values[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;
        for (int i=0; i<13 && num>0; ++i) {
            while (num >= keys[i]) {
                res += values[i];
                num -= keys[i];
            }
        }
        return res;
    }
};