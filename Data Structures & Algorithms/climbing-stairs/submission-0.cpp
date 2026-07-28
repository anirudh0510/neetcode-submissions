class Solution {
public:
    int climbStairs(int n) {
    if(n <= 2) return n;

    int prev2 = 1; // dp[1]
    int prev = 2;  // dp[2]

    for(int i = 3; i <= n; i++) {
        int curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }

    return prev;
}
};