class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<string, int> vis; 
        for(auto u : arr1){
            string s = to_string(u); string cc = ""; 
            for(int i = 0; i < s.size(); i++){
                cc += s[i]; vis[cc] = true; 
            }
        }
        int  ans = 0; 
        for(auto u : arr2){
            string s = to_string(u); string cc = "";
            for(int i = 0; i < s.size(); i++){
                cc += s[i]; if(vis[cc] == true)ans = max(ans, (i + 1)); 
            }
        }
        return ans; 
    }
};