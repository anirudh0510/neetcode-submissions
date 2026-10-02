class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // in these types of number line questions , we have to do a line sweep logic .
        // so first have the events as a vector or map on the master line and , give ans according to what is asked 
        // second methos is make a diff array , watch the video of codewithmiks

        vector<int>diff(1001);
        for(auto trip : trips){
            int count = trip[0];
            int start = trip[1];
            int end = trip[2];

            diff[start] += count;
            diff[end] -= count;
        }
        int currsum = 0;
        for(int i = 0 ; i < diff.size() ; i++){
            currsum += diff[i];

            if(currsum > capacity){
                return false;
            }
        }
        return true;


    }
};