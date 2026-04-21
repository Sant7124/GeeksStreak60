class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            // move left pointer if already 0
            while (left < right && arr[left] == 0)
                left++;

            // move right pointer if already 1
            while (left < right && arr[right] == 1)
                right--;

            // swap if needed
            if (left < right) {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};
