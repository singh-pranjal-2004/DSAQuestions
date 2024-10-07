class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for (auto str : s)
            st.push(str);

        string str;
        char prev = '-';
        while (!st.empty()) {
            cout<<prev<<" "<<str<<endl;
            char ch = st.top();

            if(prev == '-' && (ch == 'B' || ch == 'D')){
                prev = ch;
                str = ch + str;
            }else if(prev != '-'){
                if((ch == 'A' && prev == 'B') || (ch == 'C' && prev == 'D')){
                    str.erase(0, 1);
                    if(str.length()>0 && (str[0] == 'D' || str[0] == 'B')) prev = str[0];
                    else prev = '-';
                }else {
                    prev = ch;
                    str = ch + str;
                }
            }else str = ch + str;

            st.pop();
        }

        return str.length();
    }
};