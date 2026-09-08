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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;

        ListNode* temp=head;

         while(temp) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        if(nodes.size() <= 2) return;

        int l = 1;
        int r = nodes.size() - 1;

        ListNode* curr = nodes[0];

        while(l <= r) {
            // Take from right
            curr->next = nodes[r];
            curr = curr->next;
            r--;

            // Take from left
            if(l <= r) {
                curr->next = nodes[l];
                curr = curr->next;
                l++;
            }
        }

        curr->next = nullptr;
    }
        
    
};
