class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for (auto str : s)
            st.push(str);

        string str;
        char prev = '-';
        while (!st.empty()) {
            char ch = st.top();

            if(prev == '-' && (ch == 'B' || ch == 'D')){
                prev = ch;
                str = ch + str;
            }else if(prev != '-'){
                if((ch == 'A' && prev == 'B') || (ch == 'C' && prev == 'D')){
                    str.erase(0, 1);
                    if(str[0] == 'D' || str[0] == 'B') prev = str[0];
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


const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();