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

    int getLen(ListNode* head){

        int length = 0;
        while(head){
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr)
        return head;

    int length = getLen(head);
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = head;  // make circular

    k = k % length;
    int stepCnt = length - k;

    ListNode* newTail = tail;
    for (int i = 0; i < stepCnt; i++) {
        newTail = newTail->next;   // actually walk forward, starting from newTail not tail
    }

    ListNode* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}
};