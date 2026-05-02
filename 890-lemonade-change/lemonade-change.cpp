class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int collect5 = 0;
        int collect10 = 0;
        int collect20 = 0;

        for (int i = 0; i < bills.size(); i++) {

            if (bills[i] == 5) {
                collect5 += 1;
            }
            else if (bills[i] == 10) {
                if (collect5 == 0) return false;
                collect5 -= 1;
                collect10 += 1;
            }
            else { 

                
                if (collect10 >= 1 && collect5 >= 1) {
                    collect10 -= 1;
                    collect5 -= 1;
                    collect20 += 1;
                }
                
                else if (collect5 >= 3) {
                    collect5 -= 3;
                    collect20 += 1;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};