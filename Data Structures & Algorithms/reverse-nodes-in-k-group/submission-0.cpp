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
    ListNode* reverseKGroup(ListNode* head, int k) {

        int n = 0;
        ListNode* temp = head;

        while(temp){
            temp = temp->next;
            n++;
        }

        if(k == 1 || head == nullptr) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        int groups = n / k;

        while(groups--){

            ListNode* groupHead = curr;
            prev = nullptr;

            int cnt = 0;

            while(cnt < k){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                cnt++;
            }

            groupPrev->next = prev;
            groupHead->next = curr;

            groupPrev = groupHead;
        }

        return dummy.next;
    }
};