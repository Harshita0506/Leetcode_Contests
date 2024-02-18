class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int count=1;
        int sum=nums[0]+nums[1];
        for(int i=2;i<nums.size();i++)
        {
            int newsum=nums[i]+nums[i+1];
            if(sum==newsum)
            {
                count++;
            }
            else
            {
                break;
            }
            i++;
        }
        return count;
    }
};