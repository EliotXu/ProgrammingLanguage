class Solution {
public:
     int  NumberOf1(int n) {
         int number = 0;
         int mark = 0x01;
         while(mark != 0) {
             if (mark & n) number++;
             mark <<= 1;
         }
         
         return number;
     }
};