class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Nếu hai chuỗi khác độ dài, chắc chắn không phải anagram
        if len(s) != len(t):
            return False

        # Mảng đếm tần suất cho 26 ký tự tiếng Anh (a-z)
        count = [0] * 26

        # Đếm tần suất: s cộng thêm, t trừ đi
        for char_s, char_t in zip(s, t):
            count[ord(char_s) - ord('a')] += 1
            count[ord(char_t) - ord('a')] -= 1

        # Kiểm tra nếu tất cả các phần tử trong mảng đều bằng 0
        return all(c == 0 for c in count)
