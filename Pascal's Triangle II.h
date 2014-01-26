// Pascal's Triangle II 
/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

// Naive Version, forward, space 2k
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<vector<int>> res(2, vector<int>(rowIndex+1));
		for (int i=0; i<=rowIndex; ++i) {
			res[i%2][0] = res[i%2][i] = 1;
			for (int j=1; j<i; ++j)
				res[i%2][j] = res[(i-1)%2][j] + res[(i-1)%2][j-1];
		}
		return res[rowIndex%2];
	}
};

// Advanced Version, backward, space k
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res(rowIndex+1, 0);
		res[0] = 1;
		for (int i=0; i<=rowIndex; ++i)
			for (int j=i; j>=1; --j)
				res[j] = res[j] + res[j-1];
		return res;
	}
};