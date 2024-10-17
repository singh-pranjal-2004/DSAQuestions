class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num);

        vector<int>maxRight(n.length());
        for(int i = n.length()-1; i >= 0; i--){
            if(i == n.length()-1){
                maxRight[i] = i;
                continue;
            }

            if(n[maxRight[i+1]] >= n[i]) maxRight[i] = maxRight[i+1];
            else maxRight[i] = i;
        }

        for(int i = 0; i < maxRight.size(); i++){
            int maxRightIdx = maxRight[i];
            int maxRightElement = n[maxRightIdx];
            if(n[i] < maxRightElement){
                swap(n[i], n[maxRightIdx]);
                return stoi(n);
            }


            // if(maxRight[i] != i){
            //     swap(n[i], n[maxRight[i]]);
            //     return stoi(n);
            // }
        }

        return num;

    }
};