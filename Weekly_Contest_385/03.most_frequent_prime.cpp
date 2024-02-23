class Solution {
public:
    bool prime(int n){
        if(n == 1)return false;
        for(int i = 2; i *i <= n; i++){
            if(n % i == 0)return false; 
        }
        return true; 
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        
        map<int, int> ff;
        vector<int> x = {1, -1, 0, 0, 1, 1, -1, -1}, y = {0, 0, 1, -1, 1, -1, 1, -1};
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                string cur = "";
                int curx = i, cury = j;
                for(int k = 0; k < 8; k++){
                    cur = ""; 
                    curx = i, cury = j;
                    while(curx >= 0 && curx < mat.size() && cury >= 0 && cury < mat[i].size()){
                        cur += to_string(mat[curx][cury]);
                        curx += x[k], cury += y[k];
                        ++ff[stoi(cur)]; 
                    }
                }
            }
        }
        map<int, int> freq;
        for(auto u : ff){
            if(prime(u.first)){
                if(u.first >= 10)freq[u.second] = max(freq[u.second], u.first); 
            }
        }
        if(freq.empty())return -1; 
        return (*prev(freq.end())).second; 
    }
};
