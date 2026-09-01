class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Thay vì dùng 2 vòng lặp for (độ phức tạp O(n^2)) để tính target = nums[i] + nums[j] thì ta chỉ cần tìm số nào mà khi cộng với số x thì ra target (dùng 1 vòng lặp for độ phức tạp O(n))

        seen = {} # Hash map lưu theo cặp {key : value}

        for i in range(len(nums)):
            complement = target - nums[i] # Số cần tìm

            # Nếu số cần tìm đã xuất hiện trước đó
            if complement in seen:
                return [seen[complement],i]

            # Nếu chưa thấy, lưu giá trị hiện tại vào map để dùng cho các số sau
            seen[nums[i]] = i
        