class Solution {
public:
    string multiply(string num1, string num2) {
         int n = num1.size(), m = num2.size();
        if (num1 == "0" || num2 == "0") return "0";

        vector<int> result(n + m, 0);

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = result[i + j + 1] + mul;

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        string product;
        bool leadingZero = true;
        for (int num : result) {
            if (leadingZero && num == 0) continue;
            leadingZero = false;
            product += (num + '0');
        }

        return product.empty() ? "0" : product;
    }
};