class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int start = 0;
        int end = 1;
        int max_length = 1;
        bool repeat = false;
        // invariant: at the begin of each iteration,
        // s[start, end-1] is a none repeating substring
        while (end < s.size()) {
            int i = start;
            for (; i < end; ++i) {
                if (s[i] == s[end]) {
                    repeat = true;
                    break;
                }
            }
            if (repeat) {
                max_length = max(max_length, end-start);
                start = i + 1;
            }
            ++end;
            repeat = false;
        }
        return max(max_length, end - start);
    }
};
