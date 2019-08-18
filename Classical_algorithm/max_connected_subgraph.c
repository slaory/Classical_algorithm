//
//  max_connected_subgraph.c
//  Classical_algorithm
//
//  Created by fanhaifei on 2019/8/18.
//  Copyright © 2019 fanhaifei. All rights reserved.
//

#include "max_connected_subgraph.h"
#include "com_type_def.h"

/*
 * 1 - 2 \
 * | / |  5
 * 3 - 4 /
 */

/**
 * 解空间：
 * 节点0开始 每个结点两个分支， 分别是1和0，b，表示选择或者不选择， 总共选择的路径有2的n次方个。   时间复杂度为  n乘以2的n次方
 * sloved中记录的是深度遍历的路径， 比如[1 1 1 1 1] 表示5个结点均选择的路径
 * 在深度遍历过程中， 如果发现该节点无法加入，则不用在往可以加入的方向进行进行深度遍历。因此此处无法组成团的定义
 * 剪枝：如果发现当前已经被选择出来的节点cn加入剩余待选择的节点n - i大于已经被选择的某一种情况bestcn，则需要仅需深度遍历，否则不需要再次遍历，不可能是最大团。
 *      特例： 如果i=n, 表示最后一个处理完毕后， 发现cn>bestcn，则需要记录该情况，因此开头达到叶子结点中的一定是比之前每次选择都要大的情况。
 *
 *
 */

#define NODE_LEN    5

VOS_UINT32 vertex[NODE_LEN][NODE_LEN] = {
    /*1*/ /*2*/ /*3*/ /*4*/ /*5*/
    /*1*/  {0,     1,    1,    0,    0},
    /*2*/  {1,     0,    1,    1,    1},
    /*3*/  {1,     1,    0,    1,    0},
    /*4*/  {0,     1,    1,    0,    1},
    /*5*/  {0,     1,    0,    1,    0},
};                                          //图的邻居矩阵

VOS_UINT32 best_sloved[NODE_LEN];        //当前最优解
VOS_UINT32 bestcn;   //当前最优解顶点数

VOS_UINT32 sloved[NODE_LEN];     //当前解
VOS_UINT32 cn;  //当前解中已经选择顶点数

VOS_UINT32 n;   //当前顶点数量

void max_conneted_subgraph(int i)
{
    VOS_UINT32 j;
    VOS_UINT32 choosed;
    
    if (i > n) {        //已经达到叶子结点
        for (j = 0; j < n; j++) {
            best_sloved[j] = sloved[j];
        }
        bestcn = cn;
        return;
    }
    
    choosed = 1;
    for (j = 0; j < i; j++) {
        if (sloved[j] != 0 && vertex[i][j] == 0) {      //对于所有的sloved中已经被选中的，存在无法连接的点
            choosed = 0;
            break;
        }
    }
    
    if (choosed == 1) {
        sloved[i] = 1;
        cn++;
        max_conneted_subgraph(i + 1);
        sloved[i] = 0;
        cn--;
    }
    
    if (cn + n - i > bestcn) {
        sloved[i] = 0;
        max_conneted_subgraph(i + 1);
    }
    
    
}


void test_max_conneted_subgraph()
{
    VOS_UINT32 i;
 
    cn = 0;
    bestcn = 0;
    memset(best_sloved, 0, sizeof(best_sloved));
    memset(sloved, 0, sizeof(sloved));
    n = NODE_LEN;
    
    max_conneted_subgraph(0);
    printf("\nTotal is: %d\n", bestcn);
    for (i = 0; i < bestcn; i++) {
        printf("\nbest_sloved[%d]=%d  \n", i, best_sloved[i]);
    }
}


