 #include "struct.h"
 #include <stdlib.h>
 #include <stdio.h>

 
void initialize(stack *self)
{
    self->head = (struct ListNode *)malloc(sizeof(struct ListNode));
    self->size = 0;

    self->push = push;
    self->pop = pop;
}

void push(int value, stack *self)
{
    struct ListNode *tmpNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    tmpNode->next = self->head;
    self->head = tmpNode;
    self->head->val = value;
    self->size++;
}

void pop(int *value, stack *self)
{
    struct ListNode *tmpNode;
    if (self->size == 0) {
        printf("empty stack, can't pop!\n");
        return;
    }

    tmpNode = self->head;
    *value = self->head->val;
    self->head = self->head->next;
    self->size--;

    free(tmpNode);
}