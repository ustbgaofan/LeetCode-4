// 3Sum Closest 
/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

// Similar to 3Sum
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int res = num[0] + num[1] + num[2];
        int size = num.size();
        for (int i=0; i<size; ++i) {
            int l = i + 1, r = size - 1;
            while (l < r) {
                int sum = num[i] + num[l] + num[r];
                if (abs(target-sum) < abs(target-res)) res = sum;
                if (sum < target) ++l;
                else if (sum > target) --r;
                else return target;
            }
        }
        return res;
    }
};