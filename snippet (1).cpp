class Solution {
public:
     int  NumberOf1(int n) {
         int number = 0;
         while(n != 0) {
             if (n & 1) number++;
             n >>= 1;
         }
         
         return number;
     }
};