class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        //define min heap
        K=k;
       
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size() > k)pq.pop(); //since this is a min heap so minimum element will be popped
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K){
            pq.pop();
        }
        return pq.top();
    }
};