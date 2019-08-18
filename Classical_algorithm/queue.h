//
//  queue.h
//  Classical_algorithm
//
//  Created by fanhaifei on 2019/8/3.
//  Copyright © 2019 fanhaifei. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include "com_type_def.h"

typedef struct tagQueue {
    VOS_UINT32 *queueData;          // 队列数据
    VOS_UINT32 queueTotalLen;       // 队列总长度
    VOS_UINT32 startIndex;
    VOS_UINT32 endIndex;
    VOS_BOOL (*isFull)(struct tagQueue *queueContent);
    VOS_BOOL (*isEmpty)(struct tagQueue *queueContent);
    VOS_BOOL (*enQueueArray)(struct tagQueue *queueContent, VOS_INT32 enQueueNum);
    VOS_BOOL (*deQueueArray)(struct tagQueue *queueContent, VOS_INT32 *deQueueNum);
}VOS_QUEUE;

VOS_QUEUE *VOS_InitQueue(VOS_UINT32 len);
VOS_BOOL VOS_DestoryQueue(VOS_QUEUE *destoryQueue);

#endif /* queue_h */
