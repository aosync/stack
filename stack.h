/*
	stack.h - written by Alejandro Sior, inspired by rxi/vec.

	A very minimalistic stack/dynamic arrays implementation.

	Requires <stdlib.h> preincluded in including files.
*/

#define def_stack(X) \
	struct { \
		size_t mbs; \
		size_t len; \
		X *data; \
		X popcont; \
	}

#define stinit(X) ( \
	(X).mbs = sizeof((X).popcont), \
	(X).len = 0, \
	(X).data = NULL)

#define stpush(X, V) ( \
	(X).data = realloc((X).data, \
	((X).len + 1) * (X).mbs), \
	(X).data[(X).len++] = V)

#define stpop(X) ( \
	(X).popcont = (X).data[--(X).len], \
	(X).data = realloc((X).data, (X).len * (X).mbs), \
	(X).popcont)

#define stfree(X) ( \
	free((X).data), \
	(X).len = 0, \
	(X).data = NULL)
