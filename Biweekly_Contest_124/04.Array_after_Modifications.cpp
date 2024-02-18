class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        
        map<int, int> dp;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            
            dp[x + 1] = max(dp[x + 1], 1 + dp[x]);
            dp[x] = max(dp[x], 1 + dp[x - 1]);
        }
        
        int ans = 0;
        
        for (auto x : dp)
            ans = max(ans, x.second);
        
        return ans;
    }
};