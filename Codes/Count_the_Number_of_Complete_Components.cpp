class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>>nodes(n);
        int cnt=0;
        queue<int>q;
        map<int,int>mp;
        for(int i=0;i<n;++i){
            if(mp[i]!=0)    continue;
            q.push(i);
            mp[i]++;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int j=0;j<adj[node].size();++j){
                    if(mp[adj[node][j]]==0){
                        nodes[i].push_back(adj[node][j]);
                        q.push(adj[node][j]);
                        mp[adj[node][j]]++;
                    }
                }
            }
            int flag=1;
            for(int j=0;j<nodes[i].size();++j){
                if(adj[nodes[i][j]].size()!=nodes[i].size())
                    flag=0;
            }
            if(flag)
                cnt++;
        }
        return cnt;
    }
};


/*
Intuition
Using BFS to count connected components of undirected graph.

Approach
First we create adjacency List from the given edges
We iterate through the graph using BFS, (maintaining a queue).
We will also store all the nodes, we have seen till now in the nodes vector, in the index, which is the front element of queue.
Each disconnected will be identified, when the while loop ends and a new node is called with for loop
But we will not count the component which is Complete
To check this, we maintain a flag counter which will be 0 when any of the element in the node vector doesn't have the maximum no of edges of that connected component, given by nodes[i].size().

Complexity
    
Time complexity:
O(N)

Space complexity:
O(N)    :   Dur to adjacency List
*/

