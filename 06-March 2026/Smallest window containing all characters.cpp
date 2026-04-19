class Solution {
public:
    string minWindow(string &s, string &p) {
        if (p.size() > s.size()) return "";

        vector<int> need(26, 0), have(26, 0);
        for (char c : p) need[c - 'a']++;

        int required = 0;
        for (int x : need) if (x > 0) required++;

        int formed = 0, left = 0, minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            have[c - 'a']++;

            if (need[c - 'a'] > 0 && have[c - 'a'] == need[c - 'a'])
                formed++;

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char lc = s[left];
                have[lc - 'a']--;
                if (need[lc - 'a'] > 0 && have[lc - 'a'] < need[lc - 'a'])
                    formed--;
                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
