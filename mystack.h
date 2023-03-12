/*  ========== H03 - Personal Stack Implementation ============
 *
 *   Student: Sihui Lin
 *   Semester: Spring 2023
 *
 * A simple stack implementation to hold int values.
 *
 */

#ifndef MYSTACK_H
#define MYSTACK_H
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

/** Stores the maximum 'depth' of our stack.
(i.e. capacity cannot exceed MAX_DEPTH for any stack) **/
#define MAX_DEPTH 32

/** Create a node data structure to store data within
our stack. In our case, we will stores 'integers' */
typedef struct node
{
    int data;
    struct node *next;
} node_t;

/** Create a stack data structure
* Our stack holds a single pointer to a node, which
* is a linked list of nodes. 
**/
typedef struct stack
{
    int count;             // count keeps track of how many items
                           // are in the stack.
    unsigned int capacity; // Stores the maximum size of our stack
    node_t *head;          // head points to a node on the top of our stack.
} stack_t;


/**  Creates a stack
* Returns a pointer to a newly created stack.
* The stack should be initialized with data on the heap.
* (Think about what the means in terms of memory allocation)
* The stacks fields should also be initialized to default values.
*/
stack_t *create_stack(unsigned int capacity)
{
    // Modify the body of this function as needed.
    stack_t *myStack = NULL;
    // TODO: Implement me!!
    myStack = (stack_t*)malloc(sizeof(stack_t));
    myStack->head = (struct node *)malloc(sizeof(struct node));
    myStack->head->next = NULL;
    myStack->count = 0;
    myStack->capacity = capacity;
    return myStack;
}


/** Check if the stack is empty
* Returns 1 if true (The stack is completely empty)
* Returns 0 if false (the stack has at least one element enqueued)
*/
int stack_empty(stack_t *s)
{
    // TODO: Implement me!!
    if (s->head->next == NULL && s->count == 0)
        return 1;
    else
        return 0;
}

/** Check if the stack is full
* Returns 1 if true (The Stack is completely full, i.e. equal to capacity)
* Returns 0 if false (the Stack has more space available to enqueue items)
**/
int stack_full(stack_t *s)
{
    // TODO: Implement me!
    if (s->count == s->capacity)
        return 1;
    else
        return 0;
}

/** Enqueue a new item
* i.e. push a new item into our data structure
* Returns a -1 if the operation fails (otherwise returns 0 on success).
*    -> if the Stack is full that is an error, but does not crash the program.
**/
int stack_enqueue(stack_t *s, int item)
{
    // TODO: Implement me!
    struct node *Node = (struct node *)malloc(sizeof(struct node));
    Node->next = NULL;
    Node->data = item;
    // stack is not empty
    if (stack_empty(s) == 0){
        if(stack_full(s) == 0){
            // stack is not full
            Node->next = s->head->next;
            s->head->next = Node;
            s->count++;
        }else{
            // stack is full
            return -1;
        }
    }else{
        // stack is empty
        s->head->next = Node;
        s->count++;
    }
    return 0;
}

/** Dequeue an item
*   Returns the item at the front of the stack and
*   removes an item from the stack.
*   Removing an item from the empty stack should
*   print to stderr, and return the EXIT_FAILURE value
*   Example:
     fputs("no items to dequeue!\n", stderr);
     return EXIT_FAILURE
**/
int stack_dequeue(stack_t *s)
{
    // TODO: Implement me!
    int res = 0;
    if (stack_empty(s) == 0){
        // stack is not empty
        struct node *Node = (struct node *)malloc(sizeof(struct node));
        Node = s->head->next;
        res = Node->data;
        s->head->next = Node->next;
        s->count--;
        free(Node);
    }else{
        // stack is empty
        fputs("no items to dequeue!\n", stderr);
        return EXIT_FAILURE;
    }
    return res; 
}


/** returns the size of the stack. If the
 * stack hasn't been properly recreated, print to stderr, 
 * and return -1 
*/
unsigned int stack_size(stack_t *s)
{
    // TODO: Implement me!
    if(s == NULL){
        fputs("stack hasn't been properly recreated!\n", stderr);
        return -1;
    }
    return s->count;
}


/** Removes a stack and ALL of its elements from memory.
 *  This should be called before any program terminates.
 *  Simple ignores if an invalid stack is passed to it.
 **/
void free_stack(stack_t *s)
{
    // TODO: Implement me!
    if (stack_empty(s) == 1){
         // stack is empty
        free(s);
    }else{
        // stack is not empty
        while(stack_empty(s) == 0){
            stack_dequeue(s);
        }
        free(s);
    }
}
#endif
