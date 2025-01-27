#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool* checkIfPrerequisite(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    bool ** dp = (bool **) malloc(sizeof(bool *) * numCourses);
    int i = 0, j = 0, k = 0;
    for(i = 0; i < numCourses; i++) {
        dp[i] = (bool *) malloc(sizeof(bool) * numCourses);
    }
    for(i = 0; i < numCourses; i++) {
        for(j = 0; j < numCourses; j++) {
            dp[i][j] = false;
        }
    }
    
    for(i = 0; i < prerequisitesSize; i++) {
        dp[prerequisites[i][0]][prerequisites[i][1]] = true;
    }
    
    for(k = 0; k < numCourses; k++) {
        for(i = 0; i < numCourses; i++) {
            for(j = 0; j < numCourses; j++) {
                dp[i][j] = dp[i][j] || (dp[i][k] && dp[k][j]);
            }
        }
    }
    
    bool * res = (bool *) malloc(sizeof(bool) * queriesSize);
    for(i = 0; i < queriesSize; i++) {
        res[i] = dp[queries[i][0]][queries[i][1]];
    }
    return res;
}
