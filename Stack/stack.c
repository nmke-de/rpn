#include "stack.h"
#include <stdlib.h>

stack_t* stack(int val){
	stack_t* node = (stack_t*)malloc(sizeof(stack_t));
	node->content = val;
	node->next    = (stack_t*)0;
	return node;
}

stack_t* push(stack_t* stk, int val){
	stack_t* node = (stack_t*)malloc(sizeof(stack_t));
	node->content = val;
	node->next    = stk;
	return node;
}

int peek(stack_t* stk){
	return stk->content;
}

stack_t* pop(stack_t* stk){
	stack_t* node = stk->next;
	free(stk);
	return node;
}

void drop(stack_t* stk){
	while(stk->next){
		stk = pop(stk);
	}
	pop(stk);
}
