class Solution {
public:
    string decToBinComp(int num) {
        string str;
        while (num) {
            if (num & 1) {
                str += '0';
            } else {
                str += '1';
            }
            num >>= 1;
        }

        return str;
    }

    long binToDec(string str) {
        long ans = 0;
        long base = 1;

        for (int i = str.length() - 1; i >= 0; i--) {
            int n = str[i] - '0';
            ans += (n * base);
            base *= 2;
        }

        return ans;
    }

    int findComplement(int num) {
        string str = decToBinComp(num);
        reverse(str.begin(), str.end());

        long ans = binToDec(str);
        cout << ans;
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();