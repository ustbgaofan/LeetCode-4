// Restore IP Addresses
/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/


// Version 1
class Solution {
public:
    void DFS(string &s, int begin, vector<string> &res, string &path, int depth) {
        if (depth==4 && begin==s.size()) {
            res.push_back(path);
            res.back().pop_back();
        }
        if (depth==4 || begin==s.size()) return;
        
        for (int i=1; i<=3 && begin+i<=s.size(); ++i) {
            string str = s.substr(begin, i);
            if (i==2 && str[0]=='0') break;
            if (i==3 && stoi(str)>255) break;
            path += str + ".";
            DFS(s, begin+i, res, path, depth+1);
            path.resize(path.size()-i-1);
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path;
        DFS(s, 0, res, path, 0);
        return res;
    }
};

// Version 2
class Solution {
public:
    void DFS(string &s, int begin, vector<string> &res, string &path, int depth) {
        if (depth==4 && begin==s.size()) res.push_back(path);
        if (depth==4 || begin==s.size()) return;
        
        int size = path.size();
        if (size != 0) path += ".";
        for (int i=begin, num=0; i<s.size(); ++i) {
            num = num * 10 + s[i] - '0';
            if (num > 255) break;
            path += s[i];
            DFS(s, i+1, res, path, depth+1);
            if (num == 0) break;
        }
        path.resize(size);
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string path;
        DFS(s, 0, res, path, 0);
        return res;
    }
};