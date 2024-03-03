class Solution {
public:
    vector<pair<int,int> > v[1005];
    #define x first
    #define y second
    #define mp make_pair
    int dfs(int x,int f,long long sum,int mod){
        int ans=0;
        if(sum%mod==0)ans++;
        //if(f==x)ans--;
        vector<int> vv;
        for(auto it:v[x]){
            if(it.x!=f){
                if(f==x)vv.push_back(dfs(it.x,x,sum+it.y,mod));
                else
                ans+=dfs(it.x,x,sum+it.y,mod);
            }
        }
        if(vv.size()){
            ans=0;
            int sum=0;
            for(auto it:vv){
                ans+=sum*it;
                sum+=it;
            }
        }
        return ans;
        
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        for(auto it:edges){
            v[it[0]].push_back(mp(it[1],it[2]));
            v[it[1]].push_back(mp(it[0],it[2]));
        }
        vector<int> ans;
        for(int i = 0;i<edges.size()+1;i++){
            ans.push_back(dfs(i,i,0,signalSpeed));
        }
        return ans;
    }
};