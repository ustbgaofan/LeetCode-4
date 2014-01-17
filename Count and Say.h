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
        string res = "1";
        while (--n) {
            string prev = res;
            res.clear();
            int size = prev.size();
            for (int i=0; i<size;) {
                int k = 1;
                while (i+k<size && prev[i]==prev[i+k]) ++k;
                stringstream ss;
                ss << k;
                res += ss.str() + prev[i];
                i += k;
            }
        }
        return res;
    }
};