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
