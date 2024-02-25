class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        
        for(auto i:mp)
        {
            if(i.second>2)
            {
                return false;
                break;
            }
        }
        return true;
    }
};