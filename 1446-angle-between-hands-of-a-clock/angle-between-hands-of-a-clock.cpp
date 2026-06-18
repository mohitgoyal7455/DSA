class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans=abs(hour*30- 5.5*minutes);
        return min(ans,360-ans);

        
    }
};