// Longest Consecutive Sequence
/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/


// Sort, time O(nlogn), space O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int res = 1, cnt = 1;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i]==nums[i-1]) continue;
            nums[i]==nums[i-1]+1 ? ++cnt : cnt=1;
            res = max(res, cnt);
        }
        return res;
    }
};

// Hash, time O(n), space O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> h(nums.begin(), nums.end());
        int res = 0;
        for (int i : nums) {
            if (h.find(i) == h.end()) continue;
            h.erase(i);
            int l = i, r = i;
            while (h.find(r+1) != h.end()) h.erase(++r);
            while (h.find(l-1) != h.end()) h.erase(--l);
            res = max(res, r-l+1);
        }
        return res;
    }
};
