class Solution {
public:
    string inverter(string temp){
        for(int i = 0; i < temp.length(); i++){
            if(temp[i] == '0') temp[i] = '1';
            else temp[i] = '0';
        }

        return temp;
    }

    string solver(int n){
        if(n == 0) return "0";

        string temp = solver(n-1);
        string inv = inverter(temp);
        reverse(inv.begin(), inv.end());
        string ans = temp + "1" + inv;

        return ans;
    }

    char findKthBit(int n, int k) {
        string ans = solver(n);

        return ans[k-1];
    }
};