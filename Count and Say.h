// Count and Say
/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/


class Solution {
public:
    string countAndSay(int n) {
        string res("1");
        for (int i=2; i<=n; ++i) {
            string pre = res;
            res.clear();
            for (int j=0; j<pre.size(); ++j) {
                int cnt = 1;
                while (j+1<pre.size() && pre[j]==pre[j+1]) {
                    ++cnt;
                    ++j;
                }
                res += to_string(cnt) + pre[j];
            }
        }
        return res;
    }
};
