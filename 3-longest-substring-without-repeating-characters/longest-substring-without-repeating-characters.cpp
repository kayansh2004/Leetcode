class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex; // to store last seen index of characters
        int maxLen = 0;
        int start = 0;

        for (int end = 0; end < s.length(); ++end) {
            char current = s[end];

            // if character was seen and is in the current window
            if (charIndex.find(current) != charIndex.end() && charIndex[current] >= start) {
                start = charIndex[current] + 1; // move start to exclude the repeating char
            }

            charIndex[current] = end; // update last seen index
            maxLen = max(maxLen, end - start + 1); // update result
        }

        return maxLen;
    }
};