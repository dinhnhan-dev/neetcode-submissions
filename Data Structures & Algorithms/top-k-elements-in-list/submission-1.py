class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for num in nums:
            count[num] = count.get(num, 0) + 1

        arr = []
        for num, cnt in count.items():
            arr.append([num, cnt])
        arr.sort(key = lambda x: x[1])

        res = []
        while len(res) < k:
            res.append(arr.pop()[0])

        return res