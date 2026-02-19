// Last updated: 2/19/2026, 1:34:51 PM
int search(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++){
        if (nums[i] == target){
            return i;
        }
    }
    return -1;
}