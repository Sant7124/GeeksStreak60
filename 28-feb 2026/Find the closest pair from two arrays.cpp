#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int n = arr1.size();
        int m = arr2.size();
        
        int i = 0, j = m - 1;
        int diff = INT_MAX;
        vector<int> result(2);

        while (i < n && j >= 0) {
            int sum = arr1[i] + arr2[j];
            int currDiff = abs(sum - x);

            if (currDiff < diff) {
                diff = currDiff;
                result[0] = arr1[i];
                result[1] = arr2[j];
            }

            // Move pointers
            if (sum > x) {
                j--; // decrease sum
            } else {
                i++; // increase sum
            }
        }

        return result;
    }
};
