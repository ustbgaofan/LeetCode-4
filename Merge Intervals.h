// Merge Intervals
/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// time O(nlogn), space O(1)
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), [](const Interval& x, const Interval& y) {
            return x.start < y.start;
        });
        vector<Interval> res(1, intervals[0]);
        for (int i=1; i<intervals.size(); ++i) {
            if (res.back().end >= intervals[i].end) {
            } else if (res.back().end >= intervals[i].start) {
                res.back().end = intervals[i].end;
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
