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
   ListNode* curr;
bool done = false;

void solve(ListNode* head) {
    if (!head) return;

    solve(head->next);

    if (done) return;

    if (curr == head || curr->next == head) {
        head->next = NULL;
        done = true;
        return;
    }

    ListNode* temp = curr->next;
    curr->next = head;
    head->next = temp;
    curr = temp;
}

    void reorderList(ListNode* head) {
        curr = head;
        solve(head);
    }
};