#ifndef STRUCT_HH
#define STRUCT_HH

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct STACK {
    void (*initialize)(struct STACK*);
    void (*push)(int value, struct STACK*);
    void (*pop)(int *value, struct STACK*);
    
    struct ListNode *head;
    int size;
}stack;


void initialize(stack *self);
void push(int value, stack *self);
void pop(int *value, stack *self);



#endif