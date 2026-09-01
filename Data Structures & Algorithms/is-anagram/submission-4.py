class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)

        return Counter(s) == Counter(t)

        if len(s) != len(t):
            return False

        seen_s = {}
        for word in s:
            seen_s[word] = seen_s.get(word, 0) + 1

        seen_t = {}
        for word in t:
            seen_t[word] = seen_t.get(word, 0) + 1

        return seen_s == seen_t