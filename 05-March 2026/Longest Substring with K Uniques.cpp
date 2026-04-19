#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        unordered_map<char, int> freq;
        int left = 0, maxLen = -1;

        for (int right = 0; right < n; right++) {
            freq[s[right]]++;

            // Shrink window if distinct chars exceed k
            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }

            // Check if window has exactly k distinct chars
            if (freq.size() == k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};
