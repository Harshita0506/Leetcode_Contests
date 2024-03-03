class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int cnt=0,Min=2e9;
        long long ans=0;
        for(auto it:nums){
            int x=it;
            int y=it^k;
            if(x>y)ans+=x;
            else ans+=y,cnt++;
            Min=min(Min,abs(x-y));
        }
        if(cnt%2==1)ans-=Min;
        return ans;
    }
};