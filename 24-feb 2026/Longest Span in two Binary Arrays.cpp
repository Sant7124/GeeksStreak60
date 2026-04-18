#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        unordered_map<int, int> diffIndex; // stores first occurrence of difference
        int prefix1 = 0, prefix2 = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            prefix1 += a1[i];
            prefix2 += a2[i];

            int diff = prefix1 - prefix2;

            if (diff == 0) {
                // sums are equal from 0 to i
                maxLen = i + 1;
            }

            if (diffIndex.find(diff) != diffIndex.end()) {
                // found same difference before
                maxLen = max(maxLen, i - diffIndex[diff]);
            } else {
                // store first occurrence
                diffIndex[diff] = i;
            }
        }

        return maxLen;
    }
};
