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

class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while (getline(ss, tmp, '/')) {
            if (tmp=="" || tmp==".") continue;
            if (tmp==".." && !stk.empty()) stk.pop_back();
            if (tmp != "..") stk.push_back(tmp);
        }
        for (auto s : stk) res += "/" + s;
        return res.empty() ? "/" : res;
    }
};
