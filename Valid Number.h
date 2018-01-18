// Valid Number
/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/

// time O(n), space O(1)
class Solution {
public:
    bool isNumber(string s) {
        int i = 0, N = s.size();
    
        for (; i<N && s[i]==' '; ++i);  // skip the whilespaces
    
        if (i<N && (s[i]=='+' || s[i]=='-')) ++i;  // skip the sign if exist 
        
        int num = 0, pt = 0;
        for (; i<N && (isdigit(s[i]) || s[i]=='.'); ++i) s[i]=='.'? ++pt: ++num;
        if (pt>1 || num<1) return false;  // no more than one point, at least one digit
        
        if (i<N && s[i]=='e') {
            ++i;
            if (i<N && s[i]=='+' || s[i]=='-') ++i;
            for (num=0; i<N && isdigit(s[i]); ++i, ++num) ;
            if (num < 1) return false;
        }
        
        // skip the trailing whitespaces
        for (; i<N && s[i]==' '; ++i) ;
        
        return i == s.size();  // must reach the ending 0 of the string
    }
};
