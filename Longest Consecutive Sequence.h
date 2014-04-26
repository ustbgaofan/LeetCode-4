// Longest Consecutive Sequence
/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/


// Naive Version, time complexity O(nlog(n)), space complexity O(1)
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int N = num.size();
        if (N < 2) return N;
        sort(num.begin(), num.end());
        int res = 1, count = 1;
        for (int i=1; i<N; ++i) {
            if (num[i] == num[i-1]) continue;
            if (num[i] == num[i-1]+1) ++count;
            else count = 1;
            res = max(res, count);
        }
        return res;
    }
};

// Advanced Version, time complexity O(n), space complexity O(n)
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s(num.begin(), num.end());
        int res = 0;
        for (int i=0; !s.empty(); ++i) {
            if (s.find(num[i]) == s.end()) continue;
            int l = num[i], u = num[i];
            while (s.find(l-1) != s.end()) s.erase(--l);
            while (s.find(u+1) != s.end()) s.erase(++u);
            s.erase(num[i]);
            res = max(res, u-l+1);
        }
        return res;
    }
};