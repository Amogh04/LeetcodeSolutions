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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        int row = 0, col = 0;
        ListNode *p = head;
        vector<vector<int>>mat(n,vector<int>(m,-1));
        while(p!=NULL){
            mat[row][col] = p->val;
            if(col+1<m && mat[row][col+1]==-1 && (row-1==-1 || mat[row-1][col]!=-1))
                col++;
            else if(row+1<n && mat[row+1][col]==-1)     row++;
            else if(col-1>=0 && mat[row][col-1]==-1)    col--;
            else if(row-1>=0 && mat[row-1][col]==-1)    row--;
            else break;
            p=p->next;
        }
        return mat;
    }
};
/*

Approach
Initialize the matrix with -1.
Traverse the matrix along the edges. 
First traverse right, if can't, traverse down, then similarly left, and then up.
We have to add a condition : when we are going upwards, the first if() condition can become true and we might traverse right.
So, to tackle this, we only traverse right when we are at the top of the untraversed matrix i.e when row-1==-1 or mat[row-1][col]!=-1. 


Complexity

Time complexity:
O(N*M)

Space complexity:
O(k)
*/
    