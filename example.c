#include <stdlib.h>
#include "stack.h"

#include <stdio.h>

typedef def_stack(int) int_stack;

void pop(int_stack *t) {
	stpop(*t);
}

int main() {
	int_stack t;
	stinit(t);

	stpush(t, 42);
	stpush(t, 69);
	printf("%zu   %d\n", t.len, t.data[t.len-1]);

	pop(&t);

	printf("%zu   %d\n", t.len, t.data[t.len-1]);

	for (int i = 0; i < 10; i++) {
		stpush(t, i);
	}

	for (int i = t.len - 1; i >= 0; i--) {
		printf("%d\n", t.data[i]);
	}

	stfree(t);
	return 0;
}
