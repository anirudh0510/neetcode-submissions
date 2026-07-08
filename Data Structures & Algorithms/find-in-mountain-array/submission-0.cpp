/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    // Find peak index
    int findPeakElement(MountainArray &mountainArr) {
        int low = 0;
        int high = mountainArr.length() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

    // Binary Search on increasing part
    int binarySearch(MountainArray &mountainArr, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int val = mountainArr.get(mid);

            if (val == target)
                return mid;

            if (val < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    // Binary Search on decreasing part
    int reverseBinarySearch(MountainArray &mountainArr, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int val = mountainArr.get(mid);

            if (val == target)
                return mid;

            if (val > target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int peakIndex = findPeakElement(mountainArr);

        // Search in increasing part
        int result = binarySearch(mountainArr, 0, peakIndex, target);
        if (result != -1)
            return result;

        // Search in decreasing part
        return reverseBinarySearch(mountainArr, peakIndex + 1, n - 1, target);
    }
};