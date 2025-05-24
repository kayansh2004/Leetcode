class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result;
        string path;

        vector<string> phone = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        backtrack(digits, 0, phone, path, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index, const vector<string>& phone,
                   string& path, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        string letters = phone[digits[index] - '0'];
        for (char c : letters) {
            path.push_back(c);
            backtrack(digits, index + 1, phone, path, result);
            path.pop_back(); // backtrack
        }
    }
};