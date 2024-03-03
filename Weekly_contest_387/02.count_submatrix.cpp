int su[1005][1005];
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& g, int k) {
        int n=g.size(),m=g[0].size();
        for(int i=0;i<=n;++i) memset(su[i],0,sizeof(su[0]));
        int ans=0;
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=m;++j) {
                su[i][j]=su[i-1][j]+su[i][j-1]-su[i-1][j-1]+g[i-1][j-1];
                ans+=su[i][j]<=k;
            }
        }
        return ans;
    }
};