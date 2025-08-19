/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

    // Step 1: Detect if cycle exists
    do {
        if (fast == NULL || fast->next == NULL) 
            return NULL;  // no cycle

        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    // Step 2: Find the start of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // cycle start node
}
};