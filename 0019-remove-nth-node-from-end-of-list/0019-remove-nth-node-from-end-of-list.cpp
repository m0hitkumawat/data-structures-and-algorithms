class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Create a dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the nth node from the end
        ListNode* delNode = slow->next;
        slow->next = delNode->next;
        delete delNode;

        // Store the new head
        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};