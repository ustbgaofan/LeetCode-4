// Word Ladder
/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/


// Version 1, store level in every element
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<pair<string, int>> q;
        q.push(make_pair(start, 1));
        dict.erase(start);
        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            if (p.first == end) return p.second;
            for (int i=0; i<p.first.size(); ++i) {
                char t = p.first[i];
                for (char c='a'; c<='z'; ++c) {
                    p.first[i] = c;
                    if (dict.find(p.first) != dict.end()) {
                        q.push(make_pair(p.first, p.second+1));
                        dict.erase(p.first);
                    }
                }
                p.first[i] = t;
            }
        }
        return 0;
    }
};

// Version 2, use two queues to distinguish between levels
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> cq, nq;
        cq.push(start);
        dict.erase(start);
        int level = 1;
        while (!cq.empty()) {
            while (!cq.empty()) {
                string str = cq.front();
                cq.pop();
                if (str == end) return level;
                for (int i=0; i<str.size(); ++i) {
                    char t = str[i];
                    for (char c='a'; c<='z'; ++c) {
                        str[i] = c;
                        if (dict.find(str) != dict.end()) {
                            nq.push(str);
                            dict.erase(str);
                        }
                    }
                    str[i] = t;
                }
            }
            ++level;
            swap(cq, nq);
        }
        return 0;
    }
};