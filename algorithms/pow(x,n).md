class Solution {
public:
    double dfs(double x, long long n){
        if (n == 1) return x;
        else if (n==0) return 1.0;
        if ( (n&1) ) {
            return dfs(x,n/2) * dfs(x, (n+1)/2);
        }
        else {
            double a = dfs(x,n/2);
            return a*a;
        }
        //return (x & 1) ? dfs(x,n/2) * dfs(x, (n+1)/2) : dfs(x,n/2) * dfs(x,n/2);
    }
    
    double myPow(double x, int n) {
        long long a = n;
        if(n < 0) return 1/dfs(x,-a);
        else return dfs(x,a);
    }
};
