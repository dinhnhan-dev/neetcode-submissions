class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Thay dùng 2 vòng lặp for lồng nhau (độ phức tạp O(n^2)) để tính nums[i] + nums[j] == target thì ta chỉ cần tìm số nào khi cộng với số x thì bằng target là được (dùng 1 vòng lặp for độ phức tạp O(n))

        seen = {} # Hash map để lưu giá trị còn thiếu 

        for i in range(len(nums)):
            complement = target - nums[i] # Mảnh ghép còn thiếu

            # Nếu mảnh ghép đã xuất hiện trước đó thì in vị trí ra
            if complement in seen:
                return [seen[complement],i] 

            # Nếu chưa thấy, lưu số hiện tại vào map để phục vụ cho số sau
            seen[nums[i]] = i
        