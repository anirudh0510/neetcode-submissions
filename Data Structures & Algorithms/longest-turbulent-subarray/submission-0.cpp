class Solution {
public:
    int solve(int i, int prevSign, int len, vector<int>& arr) {
        if (i == arr.size()) {
            return len;
        }

        // Start a new turbulent subarray at arr[i]
        int ans = len;

        if (arr[i] > arr[i - 1]) {

            if (prevSign != 1) {
                // Continue current subarray
                ans = max(ans, solve(i + 1, 1, len + 1, arr));
            }
            else {
                // Same direction -> start from arr[i-1], arr[i]
                ans = max(ans, solve(i + 1, 1, 2, arr));
            }

        }
        else if (arr[i] < arr[i - 1]) {

            if (prevSign != -1) {
                // Continue current subarray
                ans = max(ans, solve(i + 1, -1, len + 1, arr));
            }
            else {
                // Same direction -> start new sequence
                ans = max(ans, solve(i + 1, -1, 2, arr));
            }

        }
        else {
            // Equal -> turbulence breaks
            ans = max(ans, solve(i + 1, 0, 1, arr));
        }

        return ans;
    }

    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() <= 1)
            return arr.size();

        return solve(1, 0, 1, arr);
    }
};