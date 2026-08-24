class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        duplicate = False

        nums.sort()

        for i in range(len(nums) - 1):
            if(nums[i] == nums[i+1]):
                duplicate = True

        return duplicate