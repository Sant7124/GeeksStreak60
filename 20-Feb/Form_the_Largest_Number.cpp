#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to form the largest number
    string findLargest(vector<int> &arr) {
        // Convert integers to strings
        vector<string> nums;
        for (int num : arr) {
            nums.push_back(to_string(num));
        }

        // Custom comparator: decide order by concatenation
        sort(nums.begin(), nums.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // Concatenate sorted strings
        string result;
        for (string &s : nums) {
            result += s;
        }

        // Handle case where result is all zeros
        if (result[0] == '0') return "0";

        return result;
    }
};
