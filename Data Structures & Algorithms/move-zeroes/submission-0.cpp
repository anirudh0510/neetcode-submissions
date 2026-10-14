
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        int r = 1;

        while (l < nums.size() && r < nums.size()) {
            if (nums[l] != 0) {
                l++;
                if (r <= l) r = l + 1;
            }
            else if (nums[r] == 0) {
                r++;
            }
            else {
                swap(nums[l], nums[r]);
                l++;
                r++;
            }
        }
    }
};
