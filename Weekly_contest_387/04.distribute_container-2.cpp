#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        typedef tree<vector<int>, null_type, less<vector<int>>, rb_tree_tag,
			tree_order_statistics_node_update>
	ordered_set;
        
        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};
        ordered_set st1, st2;
        st1.insert({nums[0], 0});
        st2.insert({nums[1], 1});
        
        for(int i = 2; i < nums.size(); i++){
            vector<int> tg = {nums[i], i};
            int a = st1.size() - st1.order_of_key(tg);
            int b = st2.size() - st2.order_of_key(tg);
            if (a > b){
                st1.insert(tg);
                arr1.push_back(nums[i]);
            }
            else if(a < b){
                st2.insert(tg);
                arr2.push_back(nums[i]);
            }
            else{
                if (arr1.size() <= arr2.size()){
                    st1.insert(tg);
                    arr1.push_back(nums[i]);
                }
                else {
                    st2.insert(tg);
                    arr2.push_back(nums[i]);
                }
            }
        }
        vector<int> ans;
        for(auto x: arr1) ans.push_back(x);
        for(auto x: arr2) ans.push_back(x);
        return ans;
    }
};