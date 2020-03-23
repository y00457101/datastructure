/* 二维数组做函数参数注意事项 
  1.函数申明中必须指明数组的列
    void Func(int array[][10]);  YES
    void Func(int (*array)[10]); YES 参数是个指针，指向具有10个元素的一维数组
    void Func(int *array[10]);    NO 参数是个数组，数组有10个类型是(int*)的元素
    -----------实参---------------------------形参----------------
      数组的数组 char c[8][10]        数组指针    char(*c)[10]     
      指针数组   char *c[15]          指针的指针  char **c         
      数组指针   char(*c)[10]         数组指针    char(*c)[10]     
      指针的指针 char **c             指针的指针  char **c         
    --------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSIZE 3
#define MCOLS 4

int** transpose(int** A, int ASize, int *AColSize, int* returnSize, int** returnColumnSizes){
    if(!A) return NULL;
    int col = *AColSize;
    int row = ASize;
    *returnSize = col;
    //申请可以存放col个元素的int*类型的数组大小的内存，申请到的内存地址存放在ret变量里
    int** ret = (int** )malloc(col*sizeof(int*));
    //申请可以存放col个元素的int类型的数组大小的内存，申请到的地址存在在returnColumnSizes所指向的内存单元里
    *returnColumnSizes = (int*)malloc(sizeof(int) * col);
    for( int i = 0; i < col; i++ ) {
        ret[i] = (int*)malloc(sizeof(int)*row);
        (*returnColumnSizes)[i] = row;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ret[j][i] = A[i][j];
        }
    }
    return ret;
}

void printArray(int **a, int mSize, int mColSize)
{
    int i, j;
    for (i = 0; i < mSize; i++) {
        for (j = 0; j < mColSize; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int returnSize = 0;
    int** returnColumnSizes;
    int m[MSIZE][MCOLS] = { {1, 2, 3, 9}, {1, 6, 7, 9},  {1, 7, 8, 9} };
    int colSize[MSIZE] = {4, 4, 4};

    /* 二重指针int** 和 指针数组int*[] 参数类型匹配 */
    /* 先把二位数组转化为指针数组，再做实参调用 */
    int *newM[MSIZE] = {m[0], m[1], m[2]};

    /*动态申请的指针数组也可以直接做函数实参*/
    int **newN = (int **)malloc(MSIZE*sizeof(int *));
    if (newN == NULL) return NULL;
    
    for(int i = 0; i < MSIZE; i++) {
        newN[i] = (int *)malloc(MCOLS * sizeof(int));
        if (newN == NULL) return NULL;
        memset(newN[i], 0, sizeof(newN[i]));
    }

    for(int i = 0; i < MSIZE; i++) {
        for(int j = 0; j < MCOLS; j++) {
            newN[i][j] = m[i][j];
        }
    }

    int **retM = transpose(newN, MSIZE, colSize, &returnSize, returnColumnSizes);
    printArray(retM, returnSize, (*returnColumnSizes)[0]);

    for(int i = 0; i < MSIZE; i++) {
        free(retM[i]);
    }
    free(retM);
    return 0;
}
