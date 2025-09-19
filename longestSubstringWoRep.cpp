class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int max_len = 0;
        unordered_set<char> dup_check;
        int idx_hi = 0, idx_lo = 0;

        while (idx_hi < s.length())
        {
            while (dup_check.count(s[idx_hi]))
            {
                dup_check.erase(s[idx_lo]);
                idx_lo++;
            }

            dup_check.insert(s[idx_hi]);
            max_len = max(max_len, idx_hi - idx_lo + 1);
            idx_hi++;
        }
        return max_len;
    }
};