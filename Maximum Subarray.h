// Maximum Subarray 
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/


// Dynamic Programming Version, time complexity O(n). If max sub array is [i, j],
// then [i, k] >= 0, where i <= k < j.  
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int tmpMax = A[0], res = A[0];
        // int begin = 0, end = 0, tmpBegin = 0;  // for tracking
        for (int i=1; i<n; ++i) {
            if (tmpMax < 0) {
                tmpMax = A[i];
                // tmpBegin = i;
            } else {
                tmpMax += A[i];
            }
            if (tmpMax > res) {
                res = tmpMax;
                // begin = tmpBegin;
                // end = i;
            }
        }
        return res;
    }
};

// Divide and Conquer Version, time complexity O(nlogn).
class Solution {
public:
    int maxSubArray(int A[], int l, int r) {
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
    
    int maxSubArray(int A[], int n) {
        return maxSubArray(A, 0, n-1);
    }
};