// Insert Interval
/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
 
// Position-based Version with Sequential Search, time complexity O(n)
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int N = intervals.size(), start = 0, end = 0;
        for (int i=0; i<N && newInterval.end>intervals[end].end; ++i) {
            if (newInterval.start > intervals[i].end) ++start;
            if (newInterval.end > intervals[i].end) ++end;
        }
        vector<Interval> res;
        for (int i=0; i<N; ++i) {
            if (i<start || i>end) {
                res.push_back(intervals[i]);
            } else {
                int intervalStart = min(newInterval.start, intervals[i].start);
                if (end==N || newInterval.end<intervals[end].start) {
                    res.push_back(Interval(intervalStart, newInterval.end));
                    if (end != N) res.push_back(intervals[end]);
                } else {
                    res.push_back(Interval(intervalStart, intervals[end].end));
                }
                i = end;
            }
        }
        if (start == N) res.push_back(newInterval);
        return res;
    }
};

// Position-based Version with Binary Search, time complexity O(log(n))~O(n)
class Solution {
public:
    int BinarySearch(const vector<Interval> &intervals, int value) {
        int l = 0, r = intervals.size() - 1;
        while (l <= r) {
            int m = (l + r)/2;
            if (value > intervals[m].end) l = m + 1;
            else if (m>0 && value<=intervals[m-1].end) r = m - 1;
            else return m;
        }
        return l;
    }
    
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int start = BinarySearch(intervals, newInterval.start);
        int end = BinarySearch(intervals, newInterval.end);
        int N = intervals.size();
        vector<Interval> res;
        for (int i=0; i<N; ++i) {
            if (i<start || i>end) {
                res.push_back(intervals[i]);
            } else {
                int intervalStart = min(newInterval.start, intervals[i].start);
                if (end == N || newInterval.end < intervals[end].start) {
                    res.push_back(Interval(intervalStart, newInterval.end));
                    if (end != N) res.push_back(intervals[end]);
                } else {
                    res.push_back(Interval(intervalStart, intervals[end].end));
                }
                i = end;
            }
        }
        if (start == N) res.push_back(newInterval);
        return res;
    }
};

// Value-based Version, time complexity O(n)
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;  
        int i = 0, N = intervals.size(), start = newInterval.start, end = newInterval.end;  
        for (; i<N && intervals[i].end<start; ++i) res.push_back(intervals[i]);  
        if (i < N) start = min(start, intervals[i].start);  
        for (; i<N && intervals[i].start<=end; ++i) end = max(end, intervals[i].end);
        res.push_back(Interval(start, end)); 
        res.insert(res.end(), intervals.begin()+i, intervals.end());  
        return res;
    }
};