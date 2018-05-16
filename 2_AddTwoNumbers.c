#include <stdio.h>
#include <stdlib.h>

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

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


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct ListNode *p1 = l1, *p2 = l2;
    struct ListNode *ans = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    struct ListNode *p = ans, *last = NULL, *t = NULL;

    int sum = 0;
    while (1)
    {
        if (p1 && p2)
        {
            sum += p1->val + p2->val;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1 && (p2 == NULL))
        {
            sum += p1->val;
            p1 = p1->next;
        }
        else if (p2 && (p1 == NULL))
        {
            sum += p2->val;
            p2 = p2->next;
        }
        else
        {
            break;
        }

        p->val = sum % 10;
        sum /= 10;

        /* for next node or the final node */
        p->next = t = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        last = p;
        p = p->next;
    }

    if (sum != 0)
    {
        t->val = sum;
    }
    else
    {
        /* sum is 0, we don't need a redundant 0, delete it */
        free(t);
        last->next = NULL;
    }

    return ans;
}

int main()
{
    printf("Q2: Add Two Numbers!\n");

    struct ListNode *l1 = (struct ListNode *)calloc(3, sizeof(struct ListNode));
    struct ListNode *p1 = l1;
    p1->val = 2;
    p1->next = p1 + 1;
    p1++;

    p1->val = 4;
    p1->next = p1 + 1;
    p1++;

    p1->val = 3;
    p1->next = NULL;

    struct ListNode *l2 = (struct ListNode *)calloc(3, sizeof(struct ListNode));
    struct ListNode *p2 = l2;
    p2->val = 5;
    p2->next = p2 + 1;
    p2++;

    p2->val = 6;
    p2->next = p2 + 1;
    p2++;

    p2->val = 4;
    p2->next = NULL;
    p2++;

    struct ListNode *p = addTwoNumbers(l1, l2);

    /* 243 + 564 = 807 */
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
