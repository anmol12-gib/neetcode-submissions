class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* temp3 = &dummy;

        int carry = 0;

        while(l1 || l2 || carry) {
            int sum = carry;

            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            ListNode* a = new ListNode(sum % 10);

            temp3->next = a;
            temp3 = temp3->next;
        }

        return dummy.next;
    }
};