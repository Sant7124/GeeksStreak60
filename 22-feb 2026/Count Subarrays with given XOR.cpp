#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayXor(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int prefixXOR = 0;
        int count = 0;

        for (int num : arr) {
            prefixXOR ^= num;

            if (prefixXOR == k) {
                count++;
            }

            int target = prefixXOR ^ k;
            if (freq.find(target) != freq.end()) {
                count += freq[target];
            }

            freq[prefixXOR]++;
        }

        return count;
    }
};
