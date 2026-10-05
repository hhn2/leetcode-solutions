// Last updated: 10/4/2026, 10:52:23 PM
int search(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++){
        if (nums[i] == target){
            return i;
        }
    }
    return -1;
}