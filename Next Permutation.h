// Next Permutation
/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1
*/


// time complexity O(n), space complexity O(1)
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int N = num.size(), i = N - 1;
        for (; i>=1 && num[i]<=num[i-1]; --i);
        if (i == 0) {
            reverse(num.begin(), num.end());
            return;
        }
        int j = i;
        for (; j<N && num[i-1]<num[j]; ++j);
        swap(num[j-1], num[i-1]);
        reverse(num.begin()+i, num.end());
    }
};