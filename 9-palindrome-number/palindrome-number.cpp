class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        string y = num;
        reverse(num.begin(), num.end());
        if(num==y){
            return true;
        }
        return false;
    }
};