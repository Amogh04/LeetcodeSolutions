class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        int n=s.size(),i,c1=0,c2=0;
        map<char,char>mp={ {'}','{'} , {')','('} , {']','['} };
        for(i=0;i<n;i++){
            if(s[i]=='{' || s[i]=='[' || s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.size()==0) return 0;
                if(st.top()==mp[s[i]])  st.pop();
                else return 0;
            }
        }
        if(st.size()!=0) return 0;
        return 1;

    }
};

/*

Intuition
Using stack

Approach
string should be even size. if odd it is invalid
Traverse the string.
When encounter opening bracket push it into a stack.
Now if closing bracket comes, check the top of stack, if match the bracket then pop and continue else it is invalid and stop there.
also, if closing bracket comes and stack is empty it is invalid.

Complexity

Time complexity:
O(n)

Space complexity:
O(n) : used a stack
*/