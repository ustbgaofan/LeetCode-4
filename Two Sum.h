// Two Sum
/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

// Version 1, Sort+BinarySearch, O(nlogn)+O(log n!) = O(nlogn)+O(nlogn)
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int, int>> orderedVec;
        int size = numbers.size();
        for (int i=0; i<size; ++i)
            orderedVec.push_back(make_pair(i+1, numbers[i]));
        struct MyComp {
            bool operator() (pair<int, int> p1, pair<int, int> p2) {
                return p1.second < p2.second;  
            }
        };
        sort(orderedVec.begin(), orderedVec.end(), MyComp());
        vector<int> result;
        for (int i=0; i<size; ++i) {
            int val = target - orderedVec[i].second, begin = i + 1, end = size - 1;
            bool bFind = false;
            while (begin <= end) {
                int mid = (begin + end)/2;
                if (orderedVec[mid].second < val) begin = mid + 1;
                else if (orderedVec[mid].second > val) end = mid - 1;
                else if (orderedVec[mid].second == val) {
					result.push_back(min(orderedVec[i].first, orderedVec[mid].first));
					result.push_back(max(orderedVec[i].first, orderedVec[mid].first));
					bFind = true;
                    break;
                }
            }
            if (bFind) break; 
        }
        return result;
    }
};

// Version 2, Sort+Double-sided Search, O(nlogn)+O(n)
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

// Version 3, hash(unordered_map)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> m;
        for (int i=0; i<nums.size(); ++i) m[nums[i]].push_back(i);
        for (int i=0; i<nums.size(); ++i) {
            if (m.find(target - nums[i]) != m.end()) {
                if (target == 2*nums[i] && m[nums[i]].size() == 1) continue;
                return vector<int>({i, m[target - nums[i]].back()});
            }
        }
        return vector<int>();
    }
};

// Version 4, hash(unordered_map)+one time insert
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
