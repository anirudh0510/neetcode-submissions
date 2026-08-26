/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty())return 0;
        vector<int>starts;
        vector<int>ends;

        for(auto interval : intervals){
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        };

        sort(starts.begin(), starts.end());
        sort(ends.begin() , ends.end());

        int i=0;
        int j=0;
        int rooms=0;
        int maxrooms=0;
        while(i < intervals.size()){
            if(starts[i] < ends[j]){
                rooms++;
                i++;

                maxrooms = max(maxrooms , rooms);
            }
            else{
                rooms--;
                j++;
            }
        }
        return maxrooms;
    }
};
