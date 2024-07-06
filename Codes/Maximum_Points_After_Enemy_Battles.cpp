class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int curr) {
        int n=enemyEnergies.size();
        sort(enemyEnergies.begin(),enemyEnergies.end());
        if(curr==0 || enemyEnergies[0]>curr) return 0;
        long long int pts=curr/enemyEnergies[0];
        curr%=enemyEnergies[0];
        for(int i=1;i<n;++i){
            curr+=enemyEnergies[i];
            pts+=curr/enemyEnergies[0];
            curr%=enemyEnergies[0];
        }
        return pts;
    }
};

/*
Intuition
Using Greedy.

Approach
We sort the array, then we only apply operation 1 on first element.
On all other big elements, we take the energy of enemies and increase our energy, so we can get maximum points using that energy on first(smallest) element.


Complexity

Time complexity:
O(N)

Space complexity:
O(k)
*/