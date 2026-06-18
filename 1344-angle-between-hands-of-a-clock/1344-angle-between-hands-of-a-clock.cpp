class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle;
        if(hour == 12){
            angle = minutes * 5.5;
        }else{
            angle = abs((hour * 30) - (minutes * 5.5));
        }

        angle = min(angle, 360 - angle);
        return angle;
    }
};