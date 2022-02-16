class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code here
        vector<int> results;
        int size = array.size();
        int mark = 0x01;
        int xorResult = 0;
        
        for (int i = 0; i < size; i++) {
            xorResult ^= array[i];
        }
        
        //
        while (true) {
            if (xorResult & mark) 
                break;
            mark <<= 1;
        }
        
        int firstNumber = 0, secondNumber = 0;
        for (int j = 0; j < size; j++) {
            if (mark & array[j]) {
                firstNumber ^= array[j];
            } else {
                secondNumber ^= array[j];
            }
        }
        
        if (firstNumber > secondNumber) {
            results.push_back(secondNumber);
            results.push_back(firstNumber);
        } else {
            results.push_back(firstNumber);
            results.push_back(secondNumber);
        }
        
        return results;
        
//         int tmp = 0;
//         if (results[0] > results[1]) {
//             tmp = results[0];
//             results[0] = results[1];
//             results[1] = tmp;
//         }

//         return results;
    }
};