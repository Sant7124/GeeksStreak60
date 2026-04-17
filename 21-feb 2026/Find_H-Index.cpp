#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        // Count array: how many papers have exactly i citations
        vector<int> count(n + 1, 0);

        for (int c : citations) {
            if (c >= n) {
                count[n]++;  // bucket all citations >= n
            } else {
                count[c]++;
            }
        }

        int total = 0;
        for (int i = n; i >= 0; i--) {
            total += count[i];  // total papers with >= i citations
            if (total >= i) {
                return i;
            }
        }
        return 0;
    }
};
