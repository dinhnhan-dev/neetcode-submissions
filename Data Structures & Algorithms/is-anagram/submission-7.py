class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Nếu độ dài chuỗi s và t không bằng nhau, thì không phải là Anagram
        if len(s) != len(t):
            return False
        
        # Tạo 2 dictionary rỗng để lưu tần suất xuất hiện của ký tự trong s và t
        countS, countT = {}, {}
        # Vòng lặp đếm số lần xuất hiện của từng ký tự trong chuỗi s và t
        for i in range(len(s)):
            countS[s[i]] = countS.get(s[i], 0) + 1
            countT[t[i]] = countT.get(t[i], 0) + 1
        
        # Nếu 2 dictionary bằng nhau thì 2 chuỗi là Anagram
        return countS == countT