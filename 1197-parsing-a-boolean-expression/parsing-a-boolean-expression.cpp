class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;

        for(auto ch: expression){
            if(ch == '(' || ch == ',') continue;

            if(ch == '&' || ch == '|' || ch == '!' || ch == 't' || ch == 'f') st.push(ch);
            else if(ch == ')'){
                bool hasTrue = false, hasFalse = false;
                while(st.top() != '&' && st.top() != '|' & st.top() != '!'){
                    char temp = st.top();
                    st.pop();
                    if(temp == 't') hasTrue = true;
                    else hasFalse = true;
                }

                char op = st.top();
                st.pop();

                if(op == '!') st.push((hasTrue) ? 'f' : 't');
                else if(op == '&') st.push(hasFalse ? 'f' : 't');
                else if(op == '|') st.push(hasTrue ? 't' : 'f');
            }
        }

        return st.top() == 't';
    }
};