#include "Stack/stack.h"
#include "Itoa/itoa.h"
#include "Lex/lex.h"
#include <stdio.h>

int main() {
	word_t current;
	stack_t *stk = stack(0);
	int a;
	while (nextword(&current)) {
		if (current.type == num)
			stk = push(stk, current.core.n);
		else {
			switch (current.core.k) {
				case 'D':
					stk = pop(stk);
					break;
				case 'd':
					stk = push(stk, peek(stk));
					break;
				case 'c':
					drop(stk);
					break;
				case 'p':
					puts(itoa(peek(stk), 10));
					break;
				case 'q':
				case EOF:
					goto end;
				case '+':
					a = peek(stk);
					stk = pop(stk);
					stk->content += a;
					break;
				case '-':
					a = peek(stk);
					stk = pop(stk);
					stk->content -= a;
					break;
				case '*':
					a = peek(stk);
					stk = pop(stk);
					stk->content *= a;
					break;
				case '/':
					a = peek(stk);
					stk = pop(stk);
					stk->content /= a;
					break;
				case '%':
					a = peek(stk);
					stk = pop(stk);
					stk->content %= a;
					break;
				default:
					continue;
			}
		}
	}
end:
	drop(stk);
}
