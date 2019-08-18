//
//  graph_bfs.c
//  Classical_algorithm
//
//  Created by fanhaifei on 2019/8/2.
//  Copyright © 2019 fanhaifei. All rights reserved.
//  图的广度优先遍历算法


/*
* 1 - 2 \
* | / |  5
* 3 - 4 /
*/

#include "graph_bfs.h"
#include "com_type_def.h"
#include "queue.h"

#define NODE_LEN    5
#define QUEUE_LEN  (NODE_LEN + 1)

VOS_UINT32 Vertex[NODE_LEN][NODE_LEN] = {
       /*1*/ /*2*/ /*3*/ /*4*/ /*5*/
/*1*/  {0,     1,    1,    0,    0},
/*2*/  {1,     0,    1,    1,    1},
/*3*/  {1,     1,    0,    1,    0},
/*4*/  {0,     1,    1,    0,    1},
/*5*/  {0,     1,    0,    1,    0},
};

struct tagNode {
    VOS_UINT32 nodeValue;
    VOS_UINT32 depth;
    VOS_UINT32 pre;
    VOS_UINT32 visited;
};



void bfs(VOS_UINT32 Vertex[NODE_LEN][NODE_LEN], VOS_UINT32 srcInt)
{
    VOS_QUEUE *queue;
    VOS_UINT32 deQueueNum;
    VOS_UINT32 i;
    struct tagNode nodeArray[NODE_LEN] = {0};
    
    queue = VOS_InitQueue(QUEUE_LEN);

    
    nodeArray[srcInt-1].depth = 0;
    nodeArray[srcInt-1].nodeValue = srcInt;
    nodeArray[srcInt-1].pre = 0;
    nodeArray[srcInt-1].visited = 1;
    
    queue->enQueueArray(queue, srcInt);
    while (queue->isEmpty(queue) != VOS_TRUE) {         //  为什么还要一个指针？  直接使用函数传递信息不是更好？
        queue->deQueueArray(queue, &deQueueNum);
        for (i = 0; i < NODE_LEN; i++) {
            if ((Vertex[deQueueNum - 1][i] == 1) && nodeArray[i].visited == 0) {
                nodeArray[i].visited = 1;
                nodeArray[i].nodeValue = i+1;
                nodeArray[i].pre = deQueueNum;
                nodeArray[i].depth = nodeArray[deQueueNum-1].depth + 1;
                queue->enQueueArray(queue, i+1);
            }
        }
    }
    
    for (i = 0; i < NODE_LEN; i++) {
        printf("\nvalue:%d depth:%d pre:%d visited:%d\n", nodeArray[i].nodeValue, nodeArray[i].depth, nodeArray[i].pre, nodeArray[i].visited);
    }
    
}

VOS_VOID test_bfs(VOS_VOID)
{
     bfs(Vertex, 1);
}

