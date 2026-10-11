class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<pair<int, int>> arr; // pair dùng để tạo một cặp giá trị (key, value)
        for (const auto& p : count) {
            arr.push_back({p.second, p.first}); // first: key, second: value
        }
        sort(arr.rbegin(), arr.rend()); // Sắp xếp theo thứ tự giảm dần (rbegin = reverse begin, rend = reverse end)

        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(arr[i].second); // Thêm giá trị second của phần tử thứ i trong arr
        }

        return res;
    }
};
