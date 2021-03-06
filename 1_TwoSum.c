// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:
// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
    int targetNum = 0;
    int i, j;

    int *returnInt;
    returnInt = malloc( 2 * sizeof(int));

    for (i = 0; i < numsSize; i++)
    {
        targetNum = target - nums[i];
        for (j = i + 1; j < numsSize; j++)
        {
            if (targetNum == nums[j])
            {
                returnInt[0] = i;
                returnInt[1] = j;
                return returnInt;
            }
        }
    }
    returnInt[0] = -1;
    returnInt[1] = -1;
    return returnInt;
}

int main()
{
    printf("Q1: Two Sum!\n");

    int Given_nums[4] = {2, 7, 11, 15};
    int target = 9;
    int* array_int;

    array_int = twoSum(Given_nums, sizeof(Given_nums), target);
    printf("%d %d", array_int[0], array_int[1]);

    return 0;
}

