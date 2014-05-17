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
*/

// Really Weird!

class Solution {
public:
    bool isNumber(const char *s) {
        if (s == NULL) return false;
        while (*s == ' ') ++s;
        if (*s=='+' || *s=='-') ++s;
        if (*s == '\0') return false;
        const char *begin = s, *e = strlen(s) + s - 1;
        while (*e == ' ') --e;
        int dotCount = 0, eCount = 0, plusCount = 0, minusCount = 0;
        while (s <= e) {
            if (*s=='-' && ++minusCount>0 || *s=='+' && ++plusCount>0) return false;  
            if ((*s<'0' && *s!='.' && *s!='-' && *s!='+') || (*s>'9' && *s!='e' && *s!='E')) return false;
            if (*s=='e' || *s=='E') {
                if (++eCount > 1) return false;
                if (s==begin || (!isdigit(*(s-1)) && *(s-1)!='.') || (!isdigit(*(s+1)) && *(s+1)!='-' && *(s+1)!='+')) return false;
                if (*(s+1)=='+' || *(s+1)=='-') ++s;
                if (!isdigit(*(s+1))) return false;
            }
            if (*s == '.') {
                if (eCount || ++dotCount>1) return false;
                if (!isdigit(*(s+1)) && (s==begin || s>begin && !isdigit(*(s-1)))) return false;
            }
            ++s;
        }
        return true;
    }
};

class Solution {
public:
    bool isNumber(const char *s) {
		if (s == NULL) return false;
        while(isspace(*s)) s++;
        if (*s == '+' || *s == '-') s++;    
        bool eAppear = false, dotAppear = false, firstPart = false, secondPart = false, spaceAppear = false;
        while(*s != '\0') {
			if (*s == '.') {
				if (dotAppear || eAppear || spaceAppear) return false;
                else dotAppear = true;
            } else if (*s == 'e' || *s == 'E') {
                if (eAppear || !firstPart || spaceAppear) return false;
                else eAppear = true;
            } else if (isdigit(*s)) {
                if (spaceAppear) return false;
                if (!eAppear) firstPart = true;
                else secondPart = true;
            } else if (*s == '+' || *s == '-') {
                if (spaceAppear) return false;
                if (!eAppear || !(*(s-1) == 'e' || *(s-1) == 'E')) return false;
            } else if (isspace(*s)) {
                spaceAppear = true;
			} else {
                return false;
            }
            s++;            
        }
        if (!firstPart) return false;
        else if (eAppear && !secondPart) return false;
        else return true;
    }
};