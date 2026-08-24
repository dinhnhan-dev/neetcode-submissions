class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        bool duplicate = false;
        if(nums.empty()) return false;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < (int)nums.size() - 1; i++) {
            if(nums[i] == nums[i+1]) {
                duplicate = true;
                break;
            }
        }
        return duplicate;
    }
};