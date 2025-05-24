class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
    int i = n - 2;

    // Step 1: Find first decreasing element from right
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    // Step 2: Find the next larger element and swap
    if (i >= 0) {
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the subarray after index i
    reverse(nums.begin() + i + 1, nums.end());
    }
};