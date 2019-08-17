/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

#include <stdio.h>
#include "uthash.h"

// @lc code=start
typedef struct hash_struct {
    int key;
    int value;
    UT_hash_handle hh;
} hash_struct;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    hash_struct* record = NULL;

    for (int i = 0; i < numsSize; ++i) {
        int num = nums[i];

        hash_struct* stored;
        HASH_FIND_INT(record, &num, stored);

        if (stored != NULL) {
            *returnSize = 2;

            int* result = (int*)calloc(2, sizeof(int));
            result[0] = stored->value;
            result[1] = i;

            return result;
        } else {
            stored = (hash_struct*)malloc(sizeof(hash_struct));
            stored->key = target - num;
            stored->value = i;

            HASH_ADD_INT(record, key, stored);
        }
    }

    *returnSize = 0;
    return NULL;
}
// @lc code=end

int main(int argc, char const* argv[]) {
    int* returnSize = malloc(sizeof(int));

    int* actual = twoSum((int[]){2, 7, 11, 15}, 4, 9, returnSize);
    for (size_t i = 0; i < *returnSize; ++i) {
        printf("%d, ", actual[i]);
    }

    return 0;
}
