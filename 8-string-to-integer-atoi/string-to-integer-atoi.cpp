class Solution {
public:
    int atoi(string s, int n, int sign, int i, long result) {
        if(sign * result >= INT_MAX) return INT_MAX;

        if(sign * result <= INT_MIN) return INT_MIN;

        if(i > n || s[i] > '9' || s[i] < '0') return sign * result;

        return atoi(s, n, sign, i+1, (result*10)+(s[i]-'0'));
    }

    int myAtoi(string s) {
        int i = 0, n = s.length(), sign = 1;
        while(i < n && s[i] == ' ') {
            i++;
        }

        if(s[i] == '-') {
            sign = -1;
            i++;
        }else if(s[i] == '+') i++;

        return atoi(s, n, sign, i, 0);
    }
};