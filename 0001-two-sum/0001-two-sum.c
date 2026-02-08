int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result = malloc(2 * (sizeof(int)));//memory allocation using the size of the result
    if (result==NULL) {//validating input
        *returnSize = 0;
        return NULL;
    }
    for (int i=0;i<numsSize;i++){
        for (int j=i+1;j<numsSize;j++){//loops to verify every possible pair
            if (*(nums + i) + *(nums+j) == target){
                *result = i;
                *(result + 1) = j;
                *returnSize = 2;
                return result;//inserting results in the final array and returning it
            }
        }
    }
    *returnSize = 0;
    free(result);
    return NULL;
}
