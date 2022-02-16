class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        // write code here
        int size = arr.size();
        quickSort(arr, 0, size - 1);
        
        return arr;
    }
    
    bool quickSort(vector<int>& arr, int left, int right) {
        int size = arr.size();
        if (left < 0 || right < 0 || 
                left > right || left > size || right > size) {
            return false;
        }
        
        int first = arr[left];
        int pivot = 0;
        int i = left;
        int j = right;
    
        while (i < j) {
            // 从右到左比较，大的在右边
            while (i < j && arr[j] > first) {
                j--;
            }
            if (i < j) {
                //swap value
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
            // 从左到右比较，小的在左边
            while (i < j && arr[i] < first) {
                i++;
            }
            if (i < j) {
                //swap value
                int tmp2 = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp2;
            }
        }    
        //分割点
        pivot = i;
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);

        return true;
    }
};