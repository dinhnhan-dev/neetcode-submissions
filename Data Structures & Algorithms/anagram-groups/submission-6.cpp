class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map lưu trữ: key là chuỗi đã sắp xếp, value là danh sách các từ Anagrams
        unordered_map<string, vector<string>> groups;

        for(const string& s : strs) {
            string key = s;
            // Sắp xếp các ký tự của chuỗi để làm key
            sort(key.begin(), key.end());

            // Trong C++, operator [] của unordered_map tự động tạo value mặc định
            // (vector rỗng) nếu key chưa tồn tại
            groups[key].push_back(s);
        }
        
        // Chuyển kết quả từ map sang vector 2 chiều
        vector<vector<string>> result;
        for(auto& pair:groups) {
            result.push_back(move(pair.second));
        }

        return result;
    }
};
