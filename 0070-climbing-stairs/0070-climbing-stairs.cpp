class Solution {
public:
    int fibonacci(int n) {
        int fib1 = 0, fib2 = 1, ans = 0;

        for(int i=1; i<=n; i++) {
            ans = fib1 + fib2;
            fib1 = fib2;
            fib2 = ans;
        }

        return ans;
    }

    int climbStairs(int n) {
        int ans = fibonacci(n);
        return ans;
    }
};