class Solution {
public:
    bool isValid(string s) {
        if(s[0] == ')' || s[0] == ']' || s[0] == '}') return false;

        stack<char> q;

        for(int i = 0; i < s.length(); i++){
            int val = 0;
            if(s[i] == '(') val = 1;
            else if(s[i] == ')') val = -1;
            else if(s[i] == '{') val = 2;
            else if(s[i] == '}') val = -2;
            else if(s[i] == '[') val = 3;
            else if(s[i] == ']') val = -3;

            if(!q.empty()){
                if(q.top() > 0 && q.top() + val == 0) q.pop();
                else q.push(val);
            }else q.push(val);
        }

        return q.empty();
    }
};