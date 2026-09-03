class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left < right) {
            if(s[left] != s[right]) {
                return false;
                break;
            }

            left++;
            right--;
        }

        return true;
    }
};
