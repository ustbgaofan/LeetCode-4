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

bool compare(const Interval &i, const Interval &j) { 
    return i.start < j.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> res;
        int N = intervals.size();
        for (int i=0; i<N; ) {
            int j = i + 1;
            for (; j<N && intervals[i].end>=intervals[j].start; ++j) {
                intervals[i].end = max(intervals[i].end, intervals[j].end);
            }
            res.push_back(intervals[i]);
            i = j;
        }
        return res;
    }
};