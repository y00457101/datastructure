#include<stdio.h>
#include<stdlib.h>

#define ROW 2
#define COL 3

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 A     : 二维数组地址 ASize : 二维数组的行数
 AColSize : 二维数组的列数    returnSize ：转置后的数组的行数；
 returnColumnSizes : 转置后的数组的列数
 */
int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    if(!A) return NULL;
    int col = * AColSize;
    int row = ASize;

    int** ret = (int** )malloc(col*sizeof(int*));
    *returnColumnSizes = (int*)malloc(sizeof(int) * col);
    *returnSize = col;

    for( int i = 0; i < col; i++ ) {
        ret[i] = (int*)malloc(sizeof(int)*row);
        returnColumnSizes[0][i] = row;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ret[j][i] = A[i][j];
        }
    }
    return ret;
}

void print(int **p, int row, int col)
{
	int i=0,j=0;
	for(i=0;i<row;i++) {
		for(j=0;j<col;j++) {
			printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
    int returnSize;
    int columnSize = COL;
    int **returnColumnSizes;

    int bi_array[ROW][COL] = {{4,5,6},{7,8,9}};

    int ** inputArray = (int **)malloc(sizeof(int *) * ROW);
    inputArray[0] = (int*)malloc(sizeof(int) * COL);
    inputArray[1] = (int*)malloc(sizeof(int) * COL);

    inputArray=(int **)bi_array;

    int** ret = transpose(inputArray, ROW, &columnSize, &returnSize, returnColumnSizes);
    int** ret = transpose(inputArray, ROW, &columnSize, &returnSize);
    print(ret,3,2);
    
    free(inputArray[0]);
    free(inputArray[1]);
    free(ret);
    return 0;
}


