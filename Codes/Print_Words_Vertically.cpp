class Solution {
public:
    vector<string> printVertically(string s) {
        int siz=0,mx=0;
        for(int i=0;i<s.size();++i){
            if(s[i]!=' ')   siz++;
            else    siz=0;
            mx=max(mx,siz);
        }
        vector<string>ans(mx);
        int sinceLastSpace=0;
        for(int i=0;i<s.size();++i){
            while(s[i]==' ' && sinceLastSpace<mx){
                ans[sinceLastSpace].push_back(' ');
                sinceLastSpace++;
            }
            if(s[i]==' '){
                sinceLastSpace=0;
                continue;
            }
            if(sinceLastSpace<=mx){
                ans[sinceLastSpace].push_back(s[i]);
                sinceLastSpace++;
            }
        }
        for(int i=0;i<mx;++i){
            for(int j=ans[i].size()-1;j>=0;--j){
                if(ans[i][j]==' ')
                    ans[i].pop_back();
                else    break;
            }
        }
        return ans;
    }
};

/*

Intuition
Using a counter which will be reset after each (word) space.

Approach
First we count the length of the longest word (mx), that will be the size of answer vector.
We use a counter sinceLastSpace which will keep track of the word and will be reset when another word (empty space) comes
Also this counter will go from 0 to mx, so we can use this to store values in answer vector.
If we encounter a space, and counter sinceLastSpace has not reached the end of vector, size of word is small so we store empty space until we reach the end.

Complexity

Time complexity:
O(n)

Space complexity:
O(n) : used a vector of strings
*/