class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& v) {
        int n = nums.size(), m = v.size();
        for (auto& x : v) x--;
        
        auto can = [&](int x) {
            // cout << "!: " << x << endl;
            auto a = nums;
            
            vector<bool> used(n);
            vector<int> ord;
            vector<int> last(n, -1);
            vector<bool> need(m);
            for (int i = x; i >= 0; i--) {
                // cout << "here:"  << i << endl;
                if (!used[v[i]]) {
                    need[i] = 1;
                    // cout << "here:"  << i << endl;
                    ord.push_back(v[i]);
                    // cout << "here:"  << i << endl;
                    last[v[i]] = i;
                    // cout << "here:"  << i << endl;
                    used[v[i]] = 1;
                    // cout << "here:"  << i << endl;
                }
            }
            
            if (*min_element(last.begin(), last.end()) == -1)
                return false;
            // cout << "!!: " << x << endl;
            fill(used.begin(), used.end(), 0);
            reverse(ord.begin(), ord.end());
            int p = 0;
            for (int i = 0; i <= x; i++) {
                if (need[i]) {
                    if (a[v[i]]) return false;
                    used[v[i]] = true;
                } else {
                    while (p < ord.size() && a[ord[p]] == 0) p++;
                    if (p < ord.size()) a[ord[p]]--;
                }
            }
            
            if (count(used.begin(), used.end(), false)) return false;
            return true;
        };
        
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
