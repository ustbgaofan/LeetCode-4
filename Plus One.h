// Plus One
/*
Given a number represented as an array of digits, plus one to the number.
*/


// Wrong Version, because of number value flow
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size(), value = 0; // int value?
        for (int i=0; i<size; ++i) value = value*10 + digits[i];
        ++value;
        for (int i=size-1; i>=0; --i, value /= 10) digits[i] = value % 10;
        if (int mod = value % 10) digits.insert(digits.begin(), mod);
        return digits;
    }
};

// Right Version
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        bool carryBit = ++digits[size-1] / 10;
        digits[size-1] %= 10;
        for (int i = size-2; i>=0 && carryBit; --i) {
            digits[i] += carryBit;
            carryBit = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carryBit) digits.insert(digits.begin(), 1);
        return digits;
    }
};

// Experienced Version, the first case is included in the for loop
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        bool carryBit = true;
        for (int i = size-1; i>=0 && carryBit; --i) {
            carryBit = ++digits[i] / 10;
            digits[i] %= 10;
        }
        if (carryBit) digits.insert(digits.begin(), 1);
        return digits;
    }
};