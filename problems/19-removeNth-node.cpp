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

    ListNode* removeNth(ListNode* curr, int n, int total){

        if(n == 0){

            if(n+1==total){
                return nullptr;
            }

            return curr->next;

        }

        return new ListNode(curr->val, removeNth(curr->next,n-1,total));

    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* curr = head->next;
        int  total = 1;

        while(curr != nullptr){
            total++;
            curr = curr->next;            
        }

        if(total==1) return nullptr;

        return removeNth(head,total-n,total);

    }
};