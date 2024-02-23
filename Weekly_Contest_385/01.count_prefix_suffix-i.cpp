class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
    int n = str1.length();
    if (n == 0) return true; // Empty string is prefix and suffix of any string
    int m = str2.length();
    if (n > m) return false; // Prefix can't be longer than the whole string
    
    // Check if str1 is both prefix and suffix of str2
    for (int i = 0; i < n; i++) {
        if (str1[i] != str2[i] || str1[i] != str2[m - n + i])
            return false;
    }
    return true;
}
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
    int n = words.size();
    
    // Iterate over all pairs of indices (i, j) such that i < j
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isPrefixAndSuffix(words[i], words[j]))
                count++;
        }
    }
    return count;
    }
};
