#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        unordered_set<int> s;

        // Insert all elements from both arrays into the set
        for (int x : a) {
            s.insert(x);
        }
        for (int x : b) {
            s.insert(x);
        }

        // Convert set back to vector
        vector<int> result(s.begin(), s.end());
        return result;
    }
};
