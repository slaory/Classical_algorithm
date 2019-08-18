//
//  algorithm_1.c
//  Classical_algorithm
//
//  Created by fanhaifei on 2019/8/10.
//  Copyright © 2019 fanhaifei. All rights reserved.
//

#include "algorithm_1.h"

#define PERM_NUM_MAX  4

/*******不可重复全排列  START******/
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void perm(int arrayPerm[PERM_NUM_MAX], int start, int end)
{
    int i;
    
    if (start == end) {
        for (i = 0; i <= end; i++) {
            printf("%d \t", arrayPerm[i]);
        }
        printf("\n");
        return;
    }
    
    for (i = start; i <= end; i++) {
        swap(&arrayPerm[i], &arrayPerm[start]);     // i 循环变量，每循环一次表示数字arrayPerm[i]开头的全排列, 如果全排列要求从小到大输出， 交换位置的时候注意顺序，可以修改为有序插入。
        perm(arrayPerm, start + 1, end);              //  start表示每次全排列的开始位置
        swap(&arrayPerm[i], &arrayPerm[start]);      //  i 与 start 交换的含义为， 每次将start位置的，放入下标为i的数字， 然后对start+1后面的数字进行全排列。
    }
    
}

void perm_test()
{
    int arrayPerm[PERM_NUM_MAX];
    int i;
    
    for (i = 0; i < PERM_NUM_MAX; i++) {
        arrayPerm[i] = i + 1;
    }
    
    perm(arrayPerm, 0, PERM_NUM_MAX - 1);
}
/*******不可重复全排列  END******/


/*******可重复全排列  START******/
void repeter_perm(int arrayPerm[PERM_NUM_MAX], int arrayResult[PERM_NUM_MAX], int cur, int end)
{
    int i;
    
    if (cur > end) {
        for (i = 0; i <= end; i++) {
            printf("%d \t", arrayResult[i]);
        }
        printf("\n");
        return;
    }
    
    for (i = 0; i <= end; i++) {
        arrayResult[cur] = arrayPerm[i];                       //用另外一个数组存储结果，每次都是将从0开始，将当前的存储, 因为可重复
        repeter_perm(arrayPerm, arrayResult, cur + 1, end);    //每次递归相当于设置结果数组的某一个位置cur，  每次循环相当于每次已i开头的排列
    }
    
}

void repeter_perm_test()
{
    int arrayPerm[PERM_NUM_MAX];
    int i;
    int arrayResult[PERM_NUM_MAX];
    
    for (i = 0; i < PERM_NUM_MAX; i++) {
        arrayPerm[i] = i + 1;
    }
    
    repeter_perm(arrayPerm, arrayResult, 0, PERM_NUM_MAX - 1);
    
}
/*******可重复全排列  END******/


/*******不可重复的组合  START******/
#define COMB_NUM 2
/*arrayComb等待处理的数组，  arrayResult处理结果数组，  cur当前处理的arrayResult索引下标，  start表示从arrayComb中哪个下标开始处理，  r要处理多少个*/
void comb(int arrayComb[PERM_NUM_MAX], int arrayResult[PERM_NUM_MAX], int cur, int start, int r)
{
    int i;
    
    if (r == 0) {
        for (i = 0; i < COMB_NUM; i++) {
            printf("%d \t", arrayResult[i]);
        }
        printf("\n");
        return;
    }
    
    
    for (i = start; i >= 0; i--) {
        arrayResult[cur] = arrayComb[i];
        comb(arrayComb, arrayResult, cur + 1, i - 1, r - 1);
    }
}

void comb_test()
{
    int arrayComb[PERM_NUM_MAX];
    int i;
    int arrayResult[PERM_NUM_MAX];
    
    for (i = 0; i < PERM_NUM_MAX; i++) {
        arrayComb[i] = i + 1;
    }
    
    comb(arrayComb, arrayResult, 0, PERM_NUM_MAX - 1, COMB_NUM);   // n：PERM_NUM_MAX - 1, 总共多少个元素，最大的一个下标。  r:PERM_NUM_MAX - 2要取出r个组合
}

/*******不可重复的组合  END******/
