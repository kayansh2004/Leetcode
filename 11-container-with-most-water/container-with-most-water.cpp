class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
    int left = 0, right = height.size() - 1;

    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        max_water = max(max_water, h * w);

        // Move the pointer pointing to the shorter line
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_water;
    }
};