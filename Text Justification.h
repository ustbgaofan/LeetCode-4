// Text Justification
/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/


// time O(n), space O(1)
// how many words fit in the current line;
// mod operation to manage the spaces
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for (int i=0, j, k; i<words.size(); i+=j) {
            for (j=0, k=0; i+j<words.size() && k+words[i+j].size()<=maxWidth-j; ++j) {
                k += words[i+j].size();
            }
            string line = words[i];
            for (int w=0; w<j-1; ++w) {
                if (i+j == words.size()) line += " ";  // last line
                else line += string((maxWidth-k)/(j-1) + (w < (maxWidth-k)%(j-1)), ' ');
                line += words[i+1+w];
            }
            line += string(maxWidth-line.size(), ' ');
            res.push_back(line);
        }
        return res;
    }
};
