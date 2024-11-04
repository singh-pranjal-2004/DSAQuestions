class Solution {
public:
    string compressedString(string word) {
        string comp = "";

        char tempC = word[0];
        int count = 1;

        for(int i = 1; i < word.length(); i++){
            if(count == 9 || tempC != word[i]){
                comp += count + '0';
                comp += tempC;

                tempC = word[i];
                count = 1;
            }
            else if(tempC == word[i]) count++;
        }

        comp += count + '0';
        comp += tempC;

        return comp;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();