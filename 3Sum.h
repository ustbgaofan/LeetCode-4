// 3Sum
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/


// Transform 3Sum to 2Sum. Be careful of the meaning of duplicate triplets.
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        int size = num.size();
        for (int i=0; i<size && num[i]<=0; ++i) {
            if (i>0 && num[i]==num[i-1]) continue;
            int l = i + 1, r = size - 1;
            while (l < r) {
                int sum = num[l] + num[r];
                if (sum < -num[i]) ++l;
                else if (sum > -num[i]) --r;
                else {
                    vector<int> v(1, num[i]);
                    v.push_back(min(num[l], num[r]));
                    v.push_back(max(num[l], num[r]));
                    res.push_back(v);
                    do {
                        ++l;
                    } while (l<r && num[l]==num[l-1]);
                    do {
                        --r;
                    } while (l<r && num[r]==num[r+1]);
                }
            }
        }
        return res;
    }
};