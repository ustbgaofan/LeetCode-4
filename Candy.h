// Candy
/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/


// Two-pass Version, similar to Trapping Rain Water, time complexity O(n), space complexity O(n) 
class Solution {
public:
    int candy(vector<int> &ratings) {
        int N = ratings.size();
        vector<int> candies(N, 1);
        for (int i=1; i<N; ++i) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        for (int i=N-2; i>=0; --i) {
            if (ratings[i]>ratings[i+1] && candies[i]<=candies[i+1]) {
                candies[i] = candies[i+1] + 1;
            }
        }
        int res = 0;
        for (int i=0; i<N; ++i) res += candies[i];
        return res;
    }
};

// One-pass Version, time complexity O(n), space complexity O(1)
// Hard to understand! When ratings[i] < ratings[i-1], 
// case 1:  /\
//         /  \
// case 2: ---\
//			   \
class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.empty()) return 0;
        int res = 1, cur = 1, back = 1, peak = INT_MAX;
        for (int i=1; i<ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                res += ++cur;
            } else if (ratings[i] == ratings[i-1]) {
                res += cur = 1;
                back = 1;
                peak = INT_MAX;
            } else {
                if (cur != 1) {     
                    peak = cur;
                    back = cur = 1;
                    ++res;
                } else { 
                    res += ++back;
                    if (peak == back) {
                        ++res;
                        ++peak;
                    }
                }
            }
        }
        return res;
    }
};