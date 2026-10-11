class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}  # Biến dùng để đếm số lần xuất hiện
        for num in nums:
            count[num] = count.get(num, 0) + 1

        arr = []
        for num, cnt in count.items():
            arr.append([num, cnt])
        arr.sort(key = lambda x: x[1]) # Sắp xếp theo cnt (num: [0], cnt: [1])

        res = []
        while len(res) < k:
            res.append(arr.pop()[0]) # Lấy vị trí số 0 của phần tử cuối trong arr

        return res