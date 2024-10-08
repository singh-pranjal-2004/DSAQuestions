class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int changeAvailable = 0;
        int five = 0, ten = 0, twenty = 0;

        for(auto i: bills){
            if(i == 5) five++;
            else if(i == 10) ten++;
            else twenty++;

            if(i == 10){
                if(five > 0) five--;
                else return false; 
            } 
            else if(i == 20){
                if(five > 0 && ten > 0){
                    five--;
                    ten--;
                }else if(five >= 3) five-=3;
                else return false;
            } 
        }

        return true;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();