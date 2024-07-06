class Solution {
public:
    int passThePillow(int n, int time) {
        int person = 1, direction = 1;
        while(time--){
            if(direction){
                person++;
                if(person == n) direction = 0;
            }else{
                person--;
                if(person==1) direction = 1;
            }
        }
        return person;
    }
};