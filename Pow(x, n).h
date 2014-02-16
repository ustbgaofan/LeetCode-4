// Pow(x, n)
/*
Implement pow(x, n).
*/
 
 
// When n reaches its min value, the opposite of the value 
// could not be resolved by the hardware. So n==-n is true. 
class Solution {
public:
    double pow(double x, int n) {
	    double res;
	    if (n < 0) {  
	        if (n == INT_MIN) {  // tricky!
	            res = pow(x, -(n/2));
	            res = 1 / (res*res);
	        } else {
	            res = 1 / pow(x, -n);
	        }
	    } else if (n == 0) {
		    res = 1;
	    } else if (n%2 == 1) {
		    res = pow(x, (n-1)/2);
		    res *= res*x;
	    } else {
		    res = pow(x, n/2);
		    res *= res;
	    }
	    return res;
    }
};