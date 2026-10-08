/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr) {
            ListNode* temp = curr->next; // Lưu lại nút tiếp theo
            curr->next = prev;           // Đảo ngược mối liên kết
            prev = curr;                 // Dời prev lên vị trí curr
            curr = temp;                 // Dời curr lên vị trí temp
        }
        return prev; // prev lúc này đang trỏ tới nút cuối cùng
    }
};
