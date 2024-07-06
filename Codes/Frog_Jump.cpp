class Solution {
public:
    int mx(int x, int y){
        if(x>y) return x;
        return y;
    }
    int found(vector<int>&stones, int i, int idx){
        for(;i<stones.size() && stones[i]<=idx;++i){
            if(stones[i]==idx)  return i;
        }
        return false;
    }

    bool dp(map<pair<int,int>,int>&mp, vector<int>&stones, int i, int idx, int lastjump, int curr=0){
        if(mp[{idx,lastjump}]!=0)    return curr;      // MEMOIZE
        else    mp[{idx,lastjump}]=1;

        if(i>=stones.size() || lastjump<1) return 0;
        if(!found(stones,i,idx))    return 0;
        else   i=found(stones,i,idx);

        if(i==stones.size()-1)    return 1;

        curr=mx(curr,dp(mp,stones,i+1,idx+lastjump,lastjump));
        curr=mx(curr,dp(mp,stones,i+1,idx+lastjump+1,lastjump+1));
        curr=mx(curr,dp(mp,stones,i+1,idx+lastjump-1,lastjump-1));

    return curr;
    }

    bool canCross(vector<int>& stones) {
        map<pair<int,int>,int>mp;
        return dp(mp,stones,1,1,1);
    }
};

/*

Intuition
Using Memoization

Approach
We maintain variables:
    i        : To traverse in vector stones.
    idx    : The index (which stone) we reach after jump.
    lastjump : Size of the last jump.
    curr     : current maximum no. of ways till that index.

We create a map of {idx,lastjump} which will ensure that if stone on some index is reached again by some other way but has same no. of jumps, we don't need to go further in that way.
If idx==stones.size()-1 i.e. last index has only one way and returns 1.

Now, we increase the index by jumping distances : lastjump, lastjump+1, lastjump-1 for each possible case.


Complexity

Time complexity:
O(N^3)  3 Recursive calls to check each possibility.

Space complexity:
O(N^2)
*/