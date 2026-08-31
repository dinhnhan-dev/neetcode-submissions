class Solution {
public:
    bool isAnagram(string s, string t) {
        //Sử dụng mảng đếm tần suất 26 ký tự
        if(s.length() != t.length()) {
            return false;
        }

        //Mảng đếm tần suất cho 26 ký tự tiếng Anh
        int count[26] = {0};

        //Nếu 2 chuỗi là Anagram thì số lần xuất hiện của từng từ phải giống nhau nên trong vòng lặp khi s[i]++ và t[i]-- thì kết quả phải ra là 0
        for(int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        //Nếu có ký tự nào có số lần xuất hiện khác 0 thì hai chuỗi s và t không phải là Anagram
        for (int c : count) {
            if (c != 0) {
                return false;
            }
        }

        return true;
    }
};
