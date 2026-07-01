class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxarea=0;
        while(l < r){
            int area=(r-l) * min(height[l],height[r]);
            maxarea=max(maxarea , area);
            if(height[l] < height[r]) l++;
            else r--;
        }
        return maxarea;
    }
};