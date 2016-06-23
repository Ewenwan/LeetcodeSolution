class Solution {
public:
    string longestPalindrome(string s) {
        const int len = s.size();
        if (len <= 1) return s;
        string str = preProcess(s);
        int n = str.size(), id = 0, mx = 0;
        vector<int> p(n, 1);
        for (int i = 0; i < n-1; ++i) {
            p[i] = i < mx ? min(p[2*id-i], mx-i) : 1;
            while (str[i+p[i]] == str[i-p[i]]) ++p[i];
            if (i+p[i] > mx) {
                mx = i+p[i];
                id = i;
            }
        }
        int max_len = 0, index = 0;
        for (int i = 1; i < n-1; ++i) {
            if (p[i] > max_len) {
                max_len = p[i];
                index = i;
            }
        }
        return s.substr((index-max_len)/2, max_len-1);
    }

    string preProcess(string s) {
        string res;
        res.reserve(2*s.size() + 3);
        res.push_back('$');
        res.push_back('#');
        for (int i = 0; i < s.size(); ++i) {
            res.push_back(s[i]);
            res.push_back('#');
        }
        res.push_back('^');
        return res;
    }
};
