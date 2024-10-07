class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for(auto ch: s){
            if(st.empty()){
                st.push(ch);
            }
            else{
                char tp = st.top();
                if((ch == 'B' && tp == 'A') || (ch == 'D' && tp == 'C')) st.pop();
                else st.push(ch);
            } 
        }

        return st.size();
    }
};