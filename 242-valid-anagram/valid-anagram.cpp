class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int arr[26] = {0};

        for(int i = 0; i < s.length(); i++){
            int idx1 = s[i] - 'a';
            int idx2 = t[i] - 'a';

            arr[idx1]++;
            arr[idx2]--;
        }

        for(int i = 0; i < 26; i++){
            if(arr[i]!=0) return false;
        }

        return true;
            
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();