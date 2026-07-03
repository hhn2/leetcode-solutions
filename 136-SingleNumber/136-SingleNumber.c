// Last updated: 7/2/2026, 11:16:53 PM
int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i]; // XOR all elements
    }
    return result; // The unique element remains after all XOR operations
}
