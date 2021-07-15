#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

typedef enum BOOL {
    true = 1,
    false = 0
}bool;

bool isPalindrome(struct ListNode* head);


#ifdef SOLUTION1

bool isPalindrome(struct ListNode* head)
{
    int iListSize = 0, i = 0, iTmpVal = 0;
    struct ListNode *spTmpHead = head;
    stack stack1;
    stack1.initialize = initialize;
    stack1.initialize(&stack1);

    while (spTmpHead != NULL) {
        iListSize++;
        spTmpHead = spTmpHead->next;
    }


    if (iListSize == 1) {
        return true;
    }

    for (i = 0; i < iListSize / 2; i++) {
        stack1.push(head->val, &stack1);
        head = head->next;
    }

    if (iListSize % 2 != 0) {
        head = head->next;
    }

    while (head != NULL) {
        stack1.pop(&iTmpVal, &stack1);
        if (head->val != iTmpVal) {
            return false;
        }
        head = head->next;
    }

    return true;
}
#else

struct ListNode* reverse(struct ListNode *head)
{
    struct ListNode *p1 = NULL, *p2 = head, *p3 = head;
    while (p2 != NULL) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }

    return p1;
}


bool isPalindrome(struct ListNode* head)
{
    struct ListNode *p1 = head, *p2 = head;
    bool flag = false;
    if (head == NULL) {
        return false;
    }
#if 0
    if (p2->next == NULL) {
        return true;
    }

    if (p2->next != NULL) {
        p2 = p2->next;
        if (p2->next != NULL) {
            p2 = p2->next;
            flag = true;
        }
        else {
            flag = false;
        }
    }

    if (flag == false) {
        return p1->val == p2->val;
    }

    if (flag == true) {
        while (p2->next != NULL) {
            p1 = p1->next;
            p2  = p2->next;
            if (p2->next != NULL) {
                p2 = p2->next;
            }
            else {
                flag = false;
                break;
            }
        }
    }

    if (flag == true) {
        p1 = p1->next->next;
    }
#else 
    while (p2 != NULL) {
        p1 = p1->next;
        p2 = p2->next ? p2->next->next : p2->next;
    }
#endif

    p2 = reverse(p1);
    p1 = head;

    while(p1 != NULL && p2 != NULL) {
        if (p1->val != p2->val) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}


#endif

void main(int argc, char *argv[])
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *tail = head;
    int array[6] = {1, 0, 3, 4, 0, 1}, result = 0;

    for (int i = 0; i < 6; i++) {
        head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        head = head->next;
        head->val = array[i];
    }

    head->next = NULL;
    result = isPalindrome(tail->next);

    printf("result is %d\n", result);

}