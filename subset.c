int** subsets(int* nums, int length, int** columnSizes, int* returnSize) {
    *returnSize=pow(2,length); //so if the array size is 3 like in the example, 2^3
    int **result;
    int *colSize;
    result=(int*)malloc(sizeof(int*)*(*returnSize));
    colSize=(int*)malloc(sizeof(int*)*(*returnSize));
    
    for(int i=0;i<*returnSize;i++){
        int x=i;
        int count=0;
        while(x){            
            if(x & 1)
                count++;
            x>>=1;
        }
        
        colSize[i]=count;
        
        result[i]=(int*)malloc(sizeof(int)*(colSize[i]));
    }
    *columnSizes=colSize;
    
    for(int i=0;i<*returnSize;i++){
        int x=i;
        int col=0;
        int j=0;
        while(x){
            if(x & 1) {
                result[i][col++]=nums[j];
            }                
            j++;
            x>>=1;
        }        
    }
    return result;
}