#include <bits/stdc++.h>
using namespace std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;

        string s1="";
        string s2="";

        while(temp1){
            s1+= temp1->val + '0';
            temp1=temp1->next;
        }

        while(temp2){
            s2+= temp2->val + '0';
            temp2=temp2->next;
        }

        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());

        int sum = stoi(s1)+stoi(s2);

        string sum1 = to_string(sum);
        reverse(sum1.begin(),sum1.end());

        ListNode dummy(0);
        ListNode* temp3= &dummy;

        for(int i=0;i<sum1.size();i++){
            ListNode* a = new ListNode((sum1[i] - '0'));
            temp3->next=a;
            temp3=temp3->next;
        }

        return dummy.next;
        
    }
};
