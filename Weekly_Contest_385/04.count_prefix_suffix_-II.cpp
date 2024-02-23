vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
    z[0]=n;
  return z;
}

class trie
{
    public:
    vector<pair<int,vector<int> > > a;
    trie()
    {
        a.clear();
        a.push_back(make_pair(0,vector<int>(26,-1)));
    }
    int add(string s,vector<int>& z)
    {
        int i;
        int p,ans,x;
        p=0;
        ans=0;
        for (i=0;i<s.length();i++)
        {
            x=s[i]-'a';
            if (a[p].second[x]==-1)
            {
                a[p].second[x]=a.size();
                a.push_back(make_pair(0,vector<int>(26,-1)));
            }
            p=a[p].second[x];
            if (z[s.length()-1-i]==i+1) ans+=a[p].first;
        }
        a[p].first++;
        return ans;
    }
    
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& a) {
        int i,j,n;
        long long ans;
        n=a.size();
        trie tr;
        ans=0;
        for (i=0;i<n;i++)
        {
            vector<int> z=z_function(a[i]);
            //for (j=0;j<z.size();j++)
            //    cout<<"z:"<<j<<" "<<z[j]<<endl;
            ans+=tr.add(a[i],z);
        }
        return ans;
    }
};
