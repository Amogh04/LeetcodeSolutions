class Solution {
public:
    int sol(map<pair<int,int>,int>&mp, int m, int n,int row=1, int col=1){
        if(mp[{row,col}]!=0)    return mp[{row,col}];
        if(row>m || col>n)  return 0;
        mp[{row+1,col}]=sol(mp,m,n,row+1,col);
        mp[{row,col+1}]=sol(mp,m,n,row,col+1);
        return mp[{row,col+1}]+mp[{row+1,col}];
    }

    int uniquePaths(int m, int n) {
        map<pair<int,int>,int>mp;
        mp[{m,n}]=1;
        return sol(mp,m,n);
    }
};

/*
Intuition
Memoization

Approach
This is a top-down approach using memoization.
NOTE : Here indices are not used (not from 0,0) but (row,col) are maintained from (1,1) to (m,n)
HashMap is used to store the different ways possible from a cell. Map of (m,n) is set to 1.
When the recursion reaches a cell, its map will be the sum of 2 possibile ways: going right cell and going down cell.
This happens in a recursive way until (m,n) is reached.
The last cell has no further way, so its map = 1. and all the corner cells will also have map = 1, since "if(row>m||col>n)" we return 0 and cannot go in one direction


Complexity

Time complexity:
O(m*n)

Space complexity:
O(m*n) : used a map to store 2D vector.
*/