class Solution {
public:
    int function(vector<int>& weights, int capacity) {
        int days = 1;
        int load = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > capacity) {
                days++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;

            int noofdays = function(weights, mid);

            if (noofdays <= days)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};