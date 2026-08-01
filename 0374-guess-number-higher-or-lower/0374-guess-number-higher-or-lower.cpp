/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s=1;
        int e=n;

        while(s<=e){
            int num = s + (e-s)/2;

            int val = guess(num);
            if(val == 0){
                return num;
            }else if(val == 1){
                s = num+1;
            }else{
                e = num-1;
            }
        }
        return s;
    }
};