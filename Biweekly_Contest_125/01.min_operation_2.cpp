class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        priority_queue<long long,vector<long long>,greater<long long> > pq;
        for(auto it:nums){
            pq.push(it);
        }
        int cnt=0;
        while(pq.size()>1&&pq.top()<k){
            long long x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();
            cnt++;
            pq.push(x*2+y);
        }
        return cnt;
    }
};