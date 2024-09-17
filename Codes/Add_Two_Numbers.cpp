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
        ListNode *head=NULL, *ptr=NULL;
        int c = 0;
        ListNode *p = l1, *q = l2;
        for(;!(p==NULL && q==NULL && c==0);){
            int sum = 0;
            if(p==NULL && q!=NULL)
                sum = q->val + c;
            else if(q==NULL && p!=NULL)
                sum = p->val + c;
            else if(q!=NULL && p!=NULL)
                sum = p->val + q->val + c;
            else
                sum = c;
            if(p!=NULL) p=p->next;
            if(q!=NULL) q=q->next;
            ListNode *n = new ListNode;
            n->val = sum%10;
            n->next = NULL;
            c = sum/10;
            if(head==NULL){
                head = n;
                ptr = n;
            }
            else{
                ptr->next = n;
                ptr = ptr->next;
            }
        }
        return head;
    }
};

/*


Approach
We create 2 pointers p and q to traverse in both the linked lists, and a variable c for carry.
We add (Node1 + Node2 + Previous carry) % 10 in variable sum.
and the resr i.e (Node1 + Node2 + Previous carry) / 10 will go in the carry for next iteration.
if we have traversed both the lists and the carry is zero, we stop there.



Complexity

Time complexity:
O(N)
    
Space complexity:
O(1)
*/