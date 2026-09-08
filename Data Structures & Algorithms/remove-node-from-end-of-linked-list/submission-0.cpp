class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 0;
        ListNode* temp = head;

        // Find length
        while(temp) {
            k++;
            temp = temp->next;
        }

        int pos = k - n + 1;

        // If removing head
        if(pos == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int cnt = 1;
        ListNode* temp1 = head;
        ListNode* prev = nullptr;

        while(temp1) {
            if(cnt == pos) {
                prev->next = temp1->next;
                delete temp1;
                break;
            }

            prev = temp1;
            temp1 = temp1->next;
            cnt++;
        }

        return head;
    }
};