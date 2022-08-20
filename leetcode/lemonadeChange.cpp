class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int changeState = 0;
        int change5 = 0;
        int change10 = 0;
        int change20 = 0;
        for(int pay:bills) {
            if(pay == 5) change5++;
            else if(pay == 10) {
                change10++;
                if(change5) change5--;
                else return false;
            }else {
                change20++;
                if(change10 && change5){
                    change10--;
                    change5--;
                }else if(change5 >= 3) change5 -= 3;
                else return false;
            }
        }
        
        return true;
    }
};