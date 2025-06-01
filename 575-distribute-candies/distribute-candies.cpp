class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        int eatable = n/2;
        set<int>st;
        for(auto i: candyType) {
            st.insert(i);
        }
        int setSize = st.size();

        return (setSize < eatable) ? setSize : eatable;
    }
};