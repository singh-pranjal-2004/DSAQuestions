class Solution {
public:
    int getLucky(string s, int k) {
        string str;
        for(char c: s){
            int num = c - 'a' + 1;
            str += to_string(num);
        }
 
        while(k>0){
            int num = 0;            
            for(char c: str){
                num += (c - '0');
            }

            str = to_string(num);
            k--;
        }

        return stoi(str);
    }
};
