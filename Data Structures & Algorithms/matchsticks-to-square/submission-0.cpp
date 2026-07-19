class Solution {
public:
    bool solve(int index, vector<int>& ds, vector<int>& matchsticks, int target) {

        if(index == matchsticks.size())
            return true;

        for(int i = 0; i < 4; i++) {

            if(ds[i] + matchsticks[index] > target)
                continue;

            ds[i] += matchsticks[index];

            if(solve(index + 1, ds, matchsticks, target))
                return true;

            ds[i] -= matchsticks[index];

            if(ds[i] == 0)
                break;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if(sum % 4 != 0)
            return false;

        sort(matchsticks.rbegin(), matchsticks.rend());

        vector<int> ds(4, 0);

        return solve(0, ds, matchsticks, sum / 4);
    }
};