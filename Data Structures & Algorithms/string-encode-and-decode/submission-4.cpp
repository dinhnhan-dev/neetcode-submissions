/*
Ý tưởng cối lõi: Nén theo cấu trúc "ĐỘ DÀI + KÝ TỰ PHÂN CÁCH (#) + CHUỖI"
- Thuật toán Encode (Mã hoá):
  + Duyệt qua từng từ trong danh sách, chuyển đổi theo công thức:
    [Độ dài từ] + [#] + [Nội dung từ]
  Ví dụ: Từ "neet" -> 4#neet

- Thuật toán Decode (Giải mã):
  + Đọc chuỗi từ trái qua phải, tìm dấu # để lấy con số độ dài đứng trước nó.
  + Dựa vào con số độ dài này, nhảy chính xác $N$ ký tự tiếp theo để cắt trọn vẹn từ ban đầu. 
  + Lặp lại quy trình cho đến khi đi hết chuỗi. 

- Ưu điểm lớn nhất:
  + Tránh hoàn toàn lỗi phân tách sai khi trong từ ban đầu chứa các ký tự đặc biệt (dấu cách, dấu phẩy, dấu #,...). Con số độ dài đóng vai trò là "bản đồ" giúp máy tính luôn cắt đúng vị trí.
*/
class Solution {
public:

    string encode(vector<string>& strs) {
        string res; // Chuỗi kết quả dùng để lưu toàn bộ dữ liệu đã được nén
        // Duyệt qua từng chuỗi 's' trong danh sách đầu vào 'strs'
        for(const string& s : strs) {
            res.append(to_string(s.size())); // Ghép độ dài của chuỗi 's' (chuyển số thành chuỗi) vào 'res'
            res.push_back('#'); // Thêm ký tự đánh dấu '#' ngay sau con số độ dài
            res.append(s); // Nối toàn bộ nội dung của chuỗi 's' vào đằng sau '#'
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res; // Danh sách chứa các chuỗi sau khi được giải mã
        int i = 0;          // Con trỏ 'i' dùng để đánh dấu vị trí bắt đầu đọc số độ dài
        // Vòng lặp chạy cho đến khi con trỏ 'i' đi hết chiều dài chuỗi 's'
        while (i < s.size()) {
            int j = i; // Khởi tạo con trỏ 'j' tại vị trí của 'i' để đi tìm dấu '#'
            // Tăng 'j' dần lên cho tới khi gặp ký tự '#'
            while(s[j] != '#') {
                j++;
            }
            // 'j - i' chính là số chữ số của độ dài.
            // s.substr(i, j - i) cắt ra chuỗi con biểu diễn con số độ dài (ví dụ "12").
            // stoi() chuyển chuỗi số đó thành kiểu số nguyên int 'length'.
            int length = stoi(s.substr(i, j - i));
            i = j + 1; // Bỏ qua dấu '#': Đặt 'i' ngay sau dấu '#' (vị trí bắt đầu nội dung từ)
            j = length + i; // Xác định 'j' là vị trí kết thúc của từ (bằng vị trí bắt đầu + độ dài từ)
            res.push_back(s.substr(i, length)); // Cắt đúng 'length' ký tự từ vị trí 'i' và thêm từ này vào danh sách kết quả 'res'
            i = j; // Cập nhật 'i' nhảy thẳng đến vị trí 'j' (vị trí bắt đầu của con số độ dài tiếp theo)
        }
        return res;
    }
};
