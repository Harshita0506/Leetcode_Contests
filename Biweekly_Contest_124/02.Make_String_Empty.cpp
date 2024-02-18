class Solution {
public:
    string lastNonEmptyString(string s) {
        map<char,int> freq;
        for(auto ele : s)
            freq[ele]++;
        
        int mx=0;
        for(auto &[val,f] : freq)
            mx=std::max(mx,f);
        
        string ans="";
        map<char,int> curr;
        for(auto ele : s)
        {
            curr[ele]++;
            if(curr[ele]==mx)
                ans+=ele;
        }
        
        return ans;
    }
};