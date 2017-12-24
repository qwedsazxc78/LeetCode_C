#include <stdio.h>
#include <stdlib.h>



You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };

 */

struct ListNode
{
    int val;
    struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

}

int main()
{
    ListNode nodeSum, node1, node2;
    node1.val = 10;
    node2.val = 20;

    nodeSum = addTwoNumbers(node1, node2);


    printf("Hello world!\n");
    return 0;
}
