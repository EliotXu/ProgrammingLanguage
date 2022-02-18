#include <stdio.h>
#define MIN_SIZE 1
#define MAX_SIZE 9

int sudoku[MAX_SIZE][MAX_SIZE] = {0};
int isOver = 0;

int isTheLostValue (int row, int col, int value) {
    // 同行找相同
    for (int i = 0; i < MAX_SIZE; i++) {
        if (sudoku[row][i] == value) {
            return 0;
        }
    }
    
    // 同列找相同
    for (int i = 0; i < MAX_SIZE; i++) {
        if (sudoku[i][col] == value) {
            return 0;
        }
    }
    
    // 小数独
    int smallSudokuEndRow = row / 3 * 3 + 3;
    int smallSudokuEndCol = col / 3 * 3 + 3;
    int smallSudokuStartRow = smallSudokuEndRow - 3;
    int smallSudokuStartCol = smallSudokuEndCol - 3;
    
    for (int i = smallSudokuStartRow; i < smallSudokuEndRow; i++) {
        for (int j = smallSudokuStartCol; j < smallSudokuEndCol; j++) {
            if (sudoku[i][j] == value) {
                return 0;
            }
        }
    }
    
    return 1;
}

int search(int row, int col) {
    int maxIndex = MAX_SIZE - 1;
    
    if (col > maxIndex) {
        row++;
        col = 0; // 从起始点重新开始
    }
    
    // 搜索结束
    if (row > maxIndex) {
        isOver = 1;
        return 1;
    }
    
    // start search
    // 已找到需要替换的值
    if (sudoku[row][col] == 0) {
        // 那这个值是几呢？start check
        // 穷举，1 - 9
        for (int i = 1; i <= 9; i++) {
            // i是丢失的值
            if (isTheLostValue(row, col, i)) {
                sudoku[row][col] = i;
                search(row, col + 1);
                if (isOver == 1) {
                    return 1;
                }
                // nerver found it
                sudoku[row][col] = 0;
            }
        }
    } else {
        search(row, col + 1);
    }
    
    return 0;
}

int main(void) {
    // init sudoku
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            scanf("%d", &sudoku[i][j]);            
        }
    }
    
    search(0, 0);
    
    // print sudoku
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}