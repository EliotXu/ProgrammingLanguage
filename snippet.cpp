class Solution {
public:
    int Add(int num1, int num2) {
        //无进位则和为之前的异或结果
        while(num2 != 0) {
            int c = (num1 & num2) << 1;
            num1 ^= num2;
            num2 = c;
        }
        return num1;
    }
};