// Maximum Subarray 
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/


// Dynamic Programming, time O(n), space O(n)
// m[i] represents the max sum of subarray ending at i
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int N = nums.size(), res = nums[0];
        vector<int> m(N, nums[0]);
        for (int i=1; i<N; ++i) {
            m[i] = nums[i] + (m[i-1]>0? m[i-1]: 0);
            res = max(res, m[i]);
        }
        return res;
    }
};

// Space-optimized Dynamic Programming, time O(n), space O(1)
// m[i] represents the max sum of subarray ending at i
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int N = nums.size(), res = nums[0];
        vector<int> m(2, nums[0]);
        for (int i=1; i<N; ++i) {
            m[i%2] = nums[i] + (m[(i-1)%2]>0? m[(i-1)%2]: 0);
            res = max(res, m[i%2]);
        }
        return res;
    }
};

// Divide and Conquer, time O(nlogn), space O(logn)
/*
Step1. Select the middle element of the array. So the maximum subarray may contain that middle element or not.
Step 2.1 If the maximum subarray does not contain the middle element, 
then we can apply the same algorithm to the the subarray to the left of the middle element and the subarray to the right of the middle element.
Step 2.2 If the maximum subarray does contain the middle element, 
then the result will be simply the maximum suffix subarray of the left subarray plus the maximum prefix subarray of the right subarray
Step 3 return the maximum of those three answer.
*/
class Solution {
public:
    int maxSubArray(vector<int>& A, int l, int r) {
        if (l > r) return INT_MIN;
        int mid = (l + r) / 2, lmax = 0, rmax = 0;
        for (int i=mid-1, sum=0; i>=l; --i) {
            sum += A[i];
            lmax = max(lmax, sum);
        }
        for (int i=mid+1, sum=0; i<=r; ++i) {
            sum += A[i];
            rmax = max(rmax, sum);
        }
        return max(lmax+rmax+A[mid], max(maxSubArray(A, l, mid-1), maxSubArray(A, mid+1, r)));
    }
    
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        return maxSubArray(nums, 0, nums.size()-1);
    }
};
