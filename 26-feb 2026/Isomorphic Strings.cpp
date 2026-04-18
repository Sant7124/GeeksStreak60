#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areIsomorphic(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        
        unordered_map<char, char> mapS1toS2;
        unordered_map<char, char> mapS2toS1;
        
        for (int i = 0; i < s1.size(); i++) {
            char c1 = s1[i], c2 = s2[i];
            
            // Check existing mapping
            if (mapS1toS2.count(c1)) {
                if (mapS1toS2[c1] != c2) return false;
            } else {
                mapS1toS2[c1] = c2;
            }
            
            if (mapS2toS1.count(c2)) {
                if (mapS2toS1[c2] != c1) return false;
            } else {
                mapS2toS1[c2] = c1;
            }
        }
        
        return true;
    }
};
