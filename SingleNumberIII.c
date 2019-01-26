#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_OF_CHARS 256
char* count[NO_OF_CHARS];
void countof(int *n, int s);

int* singleNumber(int* nums, int numsSize, int* ret) {
    int c = 0;
    int i;
    if(numsSize == 1 || nums == NULL)
        return NULL;
    *ret = (int *)calloc(2, sizeof(int));
    countof(nums, numsSize);
//    int **map = (int** )malloc(s*sizeof(int *));
//        map[i] = (int *)calloc(2*sizeof(int));
    for(i=0; i<numsSize; i++){
        if(count[nums[i]] == 1){
            ret[c] = nums[i];
            c++;
        }
    }
    return ret;
}

void countof(int *n, int s){
    int i;
    for(i=0; i<s; i++){
        count[n[i]]++;      
    }
}
void main(){
    
    int m[6] = {1, 2, 1, 3, 2, 5};
    int n[2];
    singleNumber(m, 6, n);
    for(int i=0; i<2; i++){
        printf("%d ,", n[i]);
    }
}




