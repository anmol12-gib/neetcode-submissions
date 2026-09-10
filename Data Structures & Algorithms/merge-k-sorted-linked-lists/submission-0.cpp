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
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* ans= &dummy;

        ListNode* temp1=list1 ; 
        ListNode* temp2=list2;

        while(temp1 && temp2){
            if(temp1->val<=temp2->val){
                ans->next=temp1;
                temp1=temp1->next;
            }

            else{
                ans->next=temp2;
                temp2=temp2->next;

            }

            ans=ans->next;
        }

        if(temp1 && temp2==nullptr){
            ans->next=temp1;
            
        }

        if(temp2 && temp1==nullptr){
            ans->next=temp2;
            
        }

        return dummy.next;

        
        
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int n=lists.size();

        for(int i=n-2;i>=0;i--){
            ListNode* temp = mergeTwoLists(lists[i],lists[i+1]);
            lists.pop_back();
            lists.pop_back();
            lists.push_back(temp);
        }

        return lists[0];
        
    }
};
