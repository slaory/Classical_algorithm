//
//  queue.c
//  Classical_algorithm
//
//  Created by fanhaifei on 2019/8/3.
//  Copyright © 2019 fanhaifei. All rights reserved.
//

#include "queue.h"
#include "com_type_def.h"

VOS_BOOL Inner_isFull(VOS_QUEUE *queueContent)
{
    if (((queueContent->endIndex + 1) % queueContent->queueTotalLen) == queueContent->startIndex) {
        return VOS_TRUE;
    }
    return VOS_FALSE;
}

VOS_BOOL Inner_isEmpty(VOS_QUEUE *queueContent)
{
    if (queueContent->startIndex == queueContent->endIndex) {
        return VOS_TRUE;
    }
    return VOS_FALSE;
}

VOS_BOOL Inner_enQueueArray(VOS_QUEUE *queueContent, VOS_INT32 enQueueNum)
{
    if (Inner_isFull(queueContent) == VOS_TRUE) {
        return VOS_FALSE;
    }
    
    queueContent->queueData[queueContent->endIndex] = enQueueNum;
    queueContent->endIndex = (queueContent->endIndex + 1) % queueContent->queueTotalLen;
    return VOS_TRUE;
}

VOS_BOOL Inner_deQueueArray(VOS_QUEUE *queueContent, VOS_INT32 *deQueueNum)
{
    if (deQueueNum == NULL) {
        return VOS_FALSE;
    }
    
    if (Inner_isEmpty(queueContent) == VOS_TRUE) {
        return VOS_FALSE;
    }
    
    *deQueueNum = queueContent->queueData[queueContent->startIndex];
    queueContent->startIndex = (queueContent->startIndex + 1) % queueContent->queueTotalLen;
    return VOS_TRUE;
}


VOS_QUEUE *VOS_InitQueue(VOS_UINT32 len)
{
    VOS_QUEUE *ret = NULL;
    
    ret = (VOS_QUEUE *)malloc(sizeof(VOS_QUEUE));
    if (ret == NULL) {
        return NULL;
    }
    
    ret->queueData = (VOS_UINT32 *)malloc((len + 1) * sizeof(VOS_UINT32));
    if (ret->queueData == NULL) {
        free(ret);
        return NULL;
    }
    
    ret->queueTotalLen = len;
    ret->startIndex = 0;
    ret->endIndex = 0;
    ret->isFull = Inner_isFull;
    ret->isEmpty =Inner_isEmpty;
    ret->enQueueArray = Inner_enQueueArray;
    ret->deQueueArray = Inner_deQueueArray;
    
    return ret;
}

VOS_BOOL VOS_DestoryQueue(VOS_QUEUE *destoryQueue)
{
    if (destoryQueue->queueData == VOS_NULL) {
        return VOS_FALSE;
    }
    
    if (destoryQueue->queueData != VOS_NULL) {
        free(destoryQueue->queueData);
    }
    
    free(destoryQueue);
    return VOS_TRUE;
}

