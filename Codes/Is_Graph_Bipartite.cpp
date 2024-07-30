class Solution {
public:
    int ans = 1;
    void DFS(vector<vector<int>>& adj, map<int,int>& vis, int parent ,int node, int flag){
        if(!vis[node])  vis[node] = flag;
        else if(vis[node]!=flag){
            ans = 0;
            return;
        }
        else if(vis[node])  return;
        for(int i=0;i<adj[node].size();++i){
            if(parent!=adj[node][i]){
                if(flag==1)
                    DFS(adj,vis,node,adj[node][i],2);
                else
                    DFS(adj,vis,node,adj[node][i],1);
            }
        }
    }

    bool isBipartite(vector<vector<int>>& adj) {
        map<int,int>vis;
        for(int i=0;i<adj.size();++i){
            if(!vis[i])
                DFS(adj,vis,-1,i,1);
        }
        return ans;
    }
};
    
/*

Intuition
using DFS

Approach
---> We use a counter which we name flag.
---> This counter will alternate between 1 and 2 when we traverse through the graph using DFS
---> The only condition when the graph is not biparite is when there is a cycle in which number of nodes is odd.
---> So, we check this condition as we traverse, we set the map to be equal to the counter of that node (1 or 2).
---> Now, when we traverse and reach the same node through a cycle, the counter will not be equal if number of nodes in that path is odd.
---> So we detect the condition that the graph is not Biparite.

Complexity

Time complexity:
O(V+E)

Space complexity:
O(V)
    
*/