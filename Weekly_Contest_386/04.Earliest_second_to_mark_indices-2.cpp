template <class T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& a, vector<int>& v) {
        int n = a.size(), m = v.size();
        for (auto& x : v) x--;
        
        auto can = [&](int k) -> bool {
            auto nums = a;

            vector<bool> mark(n);

            
            int open = 0;
            vector<bool> use(m);
            for (int i = 0; i <= k; i++) {
                if (mark[v[i]] == 0 && nums[v[i]] > 0) {
                    mark[v[i]] = 1;
                    use[i] = 1;
                } else {
                    open++;
                }
            }
            
            // cout << open << endl;
            if (open < n) return 0;
            
            int has_open = 0;
            min_pq<pair<int, int>> pq;
            for (int i = k; i >= 0; i--) {
                if (use[i]) {
                    pq.push({nums[v[i]], i});
                    has_open--;
                }
                else has_open++;
                
                if (has_open < 0) {
                    auto [x, i] = pq.top(); pq.pop();
                    has_open += 2;
                    
                    use[i] = 0;
                    mark[v[i]] = 0;
                    open++;
                }
            }
            
            open -= n;
            for (int i = 0; i < n; i++) if (!mark[i]) {
                open -= nums[i];
                if (open < 0) return false;
            }
            
            return true;
        };
        
        // int ans = can(0);
        // return ans;
        
        int lo = -1, hi = m, mid = (lo + hi) / 2;
        while (lo < mid && mid < hi) {
            if (can(mid)) hi = mid;
            else lo = mid;
            mid = (lo + hi) / 2;
        }
        
        if (hi == m) return -1;
        return hi + 1;
    }
};