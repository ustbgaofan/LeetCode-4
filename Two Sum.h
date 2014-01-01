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
    static bool compare(pair<int,int> p1, pair<int,int> p2) { 
        return p1.second < p2.second; 
    }
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int, int>> orderedVec;
        int size = numbers.size();
        for (int i=0; i<size; ++i)
            orderedVec.push_back(make_pair(i+1, numbers[i]));
        sort(orderedVec.begin(), orderedVec.end(), compare);
        vector<int> result;
        for (int i=0; i<size; ++i) {
            int val = target - orderedVec[i].second, begin = i + 1, end = size - 1;
            bool bFind = false;
            while (begin <= end) {
                int mid = (begin + end)/2;
                if (orderedVec[mid].second < val) {
                    begin = mid + 1;
                } else if (orderedVec[mid].second > val) {
                    end = mid - 1;
                } else if (orderedVec[mid].second == val) {
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