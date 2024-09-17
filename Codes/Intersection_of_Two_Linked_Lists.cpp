/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* go(int n, ListNode* head){
        while(n--){
            head = head->next;
        }
        return head;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0, n2 = 0;
        for(ListNode *p=headA;p!=NULL;p=p->next)    n1++;
        for(ListNode *p=headB;p!=NULL;p=p->next)    n2++;

        if(n2>n1)   headB = go(n2-n1,headB);
        else if(n1>n2)  headA = go(n1-n2,headA);
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
            if(headA==NULL)
                break;
        }
        return headA;
    }
};

/*

Approach
We first count the number of nodes n1, n2 in each list by traversing to end.
Then, we start traversing both linked list from the nodes which is at same distance from the end (the common list).
So to do that we have to first traverse the bigger list to |n1-n2|th node.
the we increment by 1 node and check if we have reached the common node or not.


Complexity
Time complexity:
O(N+M)

Space complexity:
O(1)
*/
    
