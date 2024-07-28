class Solution {
public:
    int DFS(vector<vector<int>>& isConnected, map<int,int>& vis, int node) {
        if(!vis[node]){
            vis[node]++;
            for(int i=0;i<isConnected.size();++i){
                if(isConnected[node][i]==1)
                    DFS(isConnected,vis,i);
            }
            return 1;
        }
        return 0;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        map<int,int>vis;
        int prov=0;
        for(int i=0;i<isConnected.size();++i){
            prov+=DFS(isConnected,vis,i);
        }
        return prov; 
    }
};

/*

Intuition
Using DFS

Approach
---> We have to compute the number of connected components of this graph (adjacency matrix).
---> We use vis to keep track of the nodes we have visited.
---> If we have not visited a node, we check all its connected nodes in matrix using DFS.

    
Complexity

Time complexity:
O(n*n)

Space complexity:
O(n) 
    
*/