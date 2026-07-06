class Solution {
public:
    bool caneatall(vector<int>&piles , int mid , int h){
        int actualhours=0;
        for(auto &x : piles){
            actualhours+=x/mid;
            if(x % mid != 0)actualhours++;
        }
        return actualhours <=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low < high){
            int mid=(low+high)/2;
            if(caneatall(piles , mid , h)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};