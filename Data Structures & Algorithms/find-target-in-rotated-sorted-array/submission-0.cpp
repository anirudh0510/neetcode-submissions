class Solution {
public:
    // Find index of minimum element (pivot)
    int findPivot(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

    // Standard Binary Search
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = findPivot(nums);

        // Search in right half
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return binarySearch(nums, pivot, n - 1, target);
        }

        // Search in left half
        return binarySearch(nums, 0, pivot - 1, target);
    }
};