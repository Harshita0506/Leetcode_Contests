class Solution {
    int solve(int left,int right,int sum,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(left>=right)
            return 0;
        
        int &val=dp[left][right];
        if(val!=-1)
            return val;
        
        val=0;
        if(nums[left]+nums[left+1]==sum)
            val=std::max(val,1+solve(left+2,right,sum,nums,dp));
        if(nums[right]+nums[right-1]==sum)
            val=std::max(val,1+solve(left,right-2,sum,nums,dp));
        if(nums[left]+nums[right]==sum)
            val=std::max(val,1+solve(left+1,right-1,sum,nums,dp));
        return val;
    }
public:
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        int sum1=nums[0]+nums[1];
        vector<vector<int>> dp1(n,vector<int>(n,-1));
        
        int sum2=nums[n-2]+nums[n-1];
        vector<vector<int>> dp2(n,vector<int>(n,-1));
        
        int sum3=nums[0]+nums[n-1];
        vector<vector<int>> dp3(n,vector<int>(n,-1));
        
        return std::max({solve(0,n-1,sum1,nums,dp1), solve(0,n-1,sum2,nums,dp2) , solve(0,n-1,sum3,nums,dp3) });
    }
};