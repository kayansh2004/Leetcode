class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    // Use long to prevent overflow in abs
    long long a = abs((long long)dividend);
    long long b = abs((long long)divisor);
    long result = 0;

    while (a >= b) {
        long long temp = b, multiple = 1;
        while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        a -= temp;
        result += multiple;
    }

    // Determine sign
    if ((dividend < 0) ^ (divisor < 0))
        return -result;
    else
        return result;
    }
};