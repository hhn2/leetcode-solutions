// Last updated: 10/4/2026, 10:55:07 PM
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int *myanswer = malloc(sizeof(int)* 2);

    for (int i = 0; i < numsSize; i++){
        for (int j = i + 1; j < numsSize; j++){
            if (*(nums + j)+ *(nums + i) == target){
                myanswer[0] = i;
                myanswer[1]= j;
                *returnSize = 2;
            }
        }
    }

    return myanswer;
    
}