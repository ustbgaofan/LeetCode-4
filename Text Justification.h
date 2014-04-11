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

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
	    int N = words.size();
	    for (int i=0; i<N; ) {
		    int j = i, avail = L;
		    for (; j<N && (int)words[j].size()<=avail; avail-=words[j].size()+1, ++j);  // !!!
		    avail += j - i;
		    string line(L, ' ');
		    if (j==N || j-i==1) {
		        for (int k=i, pos=0; k<j; ++k) {
		            line.replace(pos, words[k].size(), words[k]);
		            pos += words[k].size() + 1;
		        }
		    } else {
			    int avg = avail / (j-i-1);
			    int rem = avail % (j-i-1);
			    for (int k=i, pos=0; k<j; ++k, --rem) {
				    line.replace(pos, words[k].size(), words[k]);
				    pos += words[k].size() + avg;
				    if (rem > 0) ++pos;
			    }
		    }
		    res.push_back(line);
		    i = j;
	    }
	    return res;
    }
};