class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent < 0) {
            base = 1 / base;
            exponent = -exponent;
        }
        
        double result = 1.0;
        while(exponent) {
            if (exponent & 1) {
                result = result * base;
            }
            base *= base;
            exponent >>= 1;
        }
        
        return result;      
    }
};