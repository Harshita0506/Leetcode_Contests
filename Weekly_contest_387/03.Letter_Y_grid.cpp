class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> iny(n, vector<int>(n));
        for(int i = 0; i <= n / 2; i++){
            iny[i][i] = 1;
            iny[i][n - 1 - i] = 1;
        }
        for(int i = n / 2 + 1; i < n; i++){
            iny[i][n / 2] = 1;
        }
        int ans = n * n;
        for(int x = 0; x < 3; x++){
            for(int y = 0; y < 3; y++){
                if(x == y) continue;
                int cur = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(iny[i][j]){
                            cur += a[i][j] != y;
                        } else {
                            cur += a[i][j] != x;
                        }
                    }
                }
                ans = min(ans, cur);
            }
        }
        return ans;
    }
};