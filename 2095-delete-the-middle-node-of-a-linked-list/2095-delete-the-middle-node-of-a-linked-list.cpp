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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(!head || !head->next)
            return nullptr;
        
        int step = -1;
        ListNode* ptr = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){

            step++;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        while(step--){
            ptr = ptr->next;
        }
        ptr->next = slow->next;
        return head;
    }
};