// Two Sum
/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

// Sort+Double-sided Search, time O(nlogn), space O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> tmp;
        for (int i=0; i<nums.size(); ++i) tmp.push_back({nums[i], i});
        sort(tmp.begin(), tmp.end(), [](const pair<int, int>& x, const pair<int, int>& y){ 
            return x.first < y.first; });
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (tmp[l].first + tmp[r].first == target) break;
            else if (tmp[l].first + tmp[r].first < target) ++l;
            else --r;
        }
        return vector<int>({tmp[l].second, tmp[r].second});
    }
};

// Hash, time O(n), space O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i=0; i<nums.size(); ++i) {
            if (m.find(target - nums[i]) != m.end()) {
                return vector<int>({i, m[target - nums[i]]});
            }
            m[nums[i]] = i;
        }
        return vector<int>();
    }
};
