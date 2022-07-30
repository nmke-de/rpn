LDFLAGS += -static -s -z norelro -z noseparate-code
GIT_UPDATE = git submodule update --init

build: rpn

rpn: rpn.c Itoa/itoa.h Lex/lex.h Stack/stack.h
	$(CC) -c -o rpn.o rpn.c
	make -C Itoa -f Makefile
	make -C Lex  -f Makefile
	$(CC) -c -o Stack/stack.o Stack/stack.c
	$(LD) $(LDFLAGS) -o rpn rpn.o Itoa/itoa.o Lex/lex.o Stack/stack.o /usr/lib/libc.a

Itoa/itoa.h:
	$(GIT_UPDATE)

Lex/lex.h:
	$(GIT_UPDATE)

clean:
	rm rpn
	rm rpn.o
	rm Stack/stack.o
	make clean -C Itoa -f Makefile
	make clean -C Lex  -f Makefile

all: build clean
