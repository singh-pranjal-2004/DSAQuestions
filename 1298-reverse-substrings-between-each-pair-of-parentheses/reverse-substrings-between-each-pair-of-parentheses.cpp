class Solution {
public:
    string answerfinder(string& s, int& i){
        string str;
        while(i<s.length()){
            if(s[i] == '('){
                i++;
                str += answerfinder(s, i);
            }else if(s[i] == ')'){
                reverse(str.begin(), str.end());
                i++;
                return str;
            }else{
                str += s[i];
                i++;
            }
        }

        return str;
    }

    string reverseParentheses(string s) {
        int i = 0;
        return answerfinder(s, i);
    }
};