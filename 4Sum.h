// 4Sum 
/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/


// Transform 4Sum to 3Sum.
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int>> res;
        int size = num.size();
        for (int i=0; i<size-3; ++i) {
            if (i>0 && num[i]==num[i-1]) continue;
            for (int j=i+1; j<size; ++j) {
                if (j>i+1 && num[j]==num[j-1]) continue;
                int l = j + 1, r = size - 1;
                while (l < r) {
                    int sum = num[l] + num[r] + num[i] + num[j];
                    if (sum < target) ++l;
                    else if (sum > target) --r;
                    else {
                        int tmp[4] = {num[i], num[j], num[l], num[r]};
                        res.push_back(vector<int>(tmp, tmp+4));
                        do {
                            ++l;
                        } while (l<r && num[l]==num[l-1]);
                        do {
                            --r;
                        } while (l<r && num[r]==num[r+1]);
                    }
                }
            }
        }
        return res;
    }
};