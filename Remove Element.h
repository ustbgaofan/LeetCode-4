// Remove Element
/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/


class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int j = 0;
        for (int i=0; i<n; ++i)
            if (A[i] != elem) A[j++] = A[i];
        return j;
    }
};