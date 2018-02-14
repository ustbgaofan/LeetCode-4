// Two Sum
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

// Two pointers, time O(nlogn), space O(n)
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
            int t = target - nums[i]; 
            if (m.find(t) != m.end()) return {m[t], i};
            m[nums[i]] = i;
        }
        return {};
    }
};
