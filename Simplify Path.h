// Simplify Path
/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

/*--------------------------------------------------------------------------------------------------
The rule of Unix-style path includes:
An absolute path always starts from the root directory, i.e. "/".
"." represents the current directory itself.
".." goes upwards to the parent directory if exists. E.g. "/a/b/.." == "/a", while "/../" == "/".
Redundant slashes can be ignored. E.g. "/a///b" == "/a/b"
--------------------------------------------------------------------------------------------------*/


// Stack Version with self-implemented split function
// space complexity O(n)
class Solution {
public:
    vector<string> split(const string &str, const string &sep) {
	    char cstr[str.size()+1], csep[sep.size()+1];
	    strcpy(cstr, str.c_str());
	    strcpy(csep, sep.c_str());
	    char *csubstr = strtok(cstr, csep);
	    vector<string> res;
	    while (csubstr != NULL) {
		    res.push_back(csubstr);
		    csubstr = strtok(NULL, csep);
	    }
	    return res;
    }

    string simplifyPath(string path) {
        vector<string> v = split(path, "/");
        stack<string> stk;
        for (int i=0; i<v.size(); ++i) {
            if (v[i]!=".." && v[i]!=".") stk.push(v[i]);
            else if (v[i] == ".." && !stk.empty()) stk.pop();  // corner case: /..
        }
        if (stk.empty()) return "/";
        string res;
        while (!stk.empty()) {
            res.insert(0, "/"+stk.top());
            stk.pop();
        }
        return res;
    }
};

// Vector based Stack Version without self-implemented split function
// space complexity O(n)
class Solution {
public:
    string simplifyPath(string path) {
        if (path.back() != '/') path += "/";
        vector<string> stk;
        int size = path.size();
        for (int i=0; i<size; ++i) {
            while (i<size && path[i]=='/') ++i;
            if (i == size) break;
            int start = i;
            while (i<size && path[i]!='/') ++i;
            string str = path.substr(start, i-start);
            if (str!=".." && str!=".") stk.push_back(str);
            else if (str==".." && !stk.empty()) stk.pop_back();
        }
        if (stk.empty()) return "/";
        string res;
        for (int i=0; i<stk.size(); ++i) res += "/" + stk[i];
        return res;
    }
};

// In Place Version, without extra space
class Solution {
public:
    string simplifyPath(string path) {
        if (path.back() != '/') path += "/";
        int size = path.size(), j = 1;
        for (int i=0; i<size; ++i) {
            while (i<size && path[i]=='/') ++i;
            if (i == size) break;
            int start = i;
            while (i<size && path[i]!='/') ++i;
            if (i-start==2 && path[i-1]=='.' && path[i-2]=='.') {
                if (j > 1) while (--j>1 && path[j-1]!='/');
            } else if (i-start>2 || path[i-1]!='.') {
                for (int k=0; k<i-start+1; ++k) path[j++] = path[start+k];
            }
        }
        return j==1 ? "/": path.substr(0, --j);
    }
};