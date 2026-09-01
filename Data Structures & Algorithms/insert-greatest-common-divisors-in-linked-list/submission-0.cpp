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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            int a = curr->val;
            int b = curr->next->val;

            // Find GCD
            int x = a, y = b;
            while (y != 0) {
                int temp = y;
                y = x % y;
                x = temp;
            }

            ListNode* node = new ListNode(x);

            node->next = curr->next;
            curr->next = node;

            curr = node->next;
        }

        return head;
    }
};