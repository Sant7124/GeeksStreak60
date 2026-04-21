class Solution {
  public:
    bool isPower(int x, int y) {
        // Edge case
        if (x == 1) return y == 1;

        // Divide y by x repeatedly
        while (y % x == 0) {
            y = y / x;
        }

        return y == 1;
    }
};
