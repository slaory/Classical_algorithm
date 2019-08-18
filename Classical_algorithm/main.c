//
//  main.c
//  Classical_algorithm
//
//  Created by fanhaifei on 2019/8/2.
//  Copyright © 2019 fanhaifei. All rights reserved.
//

#include <stdio.h>
#include "graph_bfs.h"
#include "algorithm_1.h"
#include "com_type_def.h"


int main(int argc, const char * argv[]) {
    //test_bfs();    //深度遍历递归测试
    
    //perm_test();      //全排列测试.
    //repeter_perm_test();    // 可重复的全排列测试
    //comb_test();       //不可重复的组合
    
    test_max_conneted_subgraph();
    
    printf("Hello, World!\n");
    return 0;
}
