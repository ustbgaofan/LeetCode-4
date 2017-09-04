// Word Ladder
/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

// Graph, BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> h(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        h.erase(beginWord);
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            if (f.first == endWord) return f.second;
            for (int i=0; i<f.first.size(); ++i) {
                char t = f.first[i];
                for (char c='a'; c<='z'; ++c) {
                    f.first[i] = c;
                    if (h.find(f.first) == h.end()) continue;
                    q.push({f.first, f.second+1});
                    h.erase(f.first);
                }
                f.first[i] = t;
            }
        }
        return 0;
    }
};
