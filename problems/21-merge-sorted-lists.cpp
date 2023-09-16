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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        //get list to start

        ListNode *head = list1;

        if(list1->val > list2->val){
            head = list2;
            list2 = list2->next;
        }else{
            list1 = list1->next;
        }

        ListNode *tail = head;

        while(list1 && list2){

            //get the next value
            if(list1->val > list2->val){
                
                tail->next = list2;
                list2 = list2->next;

            }else{
                tail->next = list1;
                list1 = list1->next;

            }
            //update the tail
            tail = tail->next;


        }

        //add remaining of list
        if(list1 == NULL){
            tail->next = list2;
        }else{
            tail->next = list1;
        }

        return head;


    }
};