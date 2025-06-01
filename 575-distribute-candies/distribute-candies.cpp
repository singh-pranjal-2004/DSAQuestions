class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();

        set<int>st;
        for(auto i: candyType) {
            st.insert(i);
        }

        return st.size()<n/2? st.size() : n/2;
    }
};