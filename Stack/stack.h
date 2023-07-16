#ifndef STACK_H
#define STACK_H
typedef struct stack_t {
	struct stack_t *next;
	int content;
	// TODO Add and implement stack counter
} stack_t;

stack_t *stack(int);
stack_t *push(stack_t *, int);
stack_t *pop(stack_t *);
int peek(stack_t *);
void drop(stack_t *);
#endif
