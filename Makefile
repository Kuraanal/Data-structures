all: example-list example-stack example-hash example-bstree

example-list: example-list.c src/linked-list.c src/linked-list.h
	clang -o example-list example-list.c src/linked-list.c -g -gdwarf-4

example-stack: example-stack.c src/stack.c src/stack.h
	clang -o example-stack example-stack.c src/stack.c src/linked-list.c -g -gdwarf-4

example-hash: example-hash.c src/hash.c src/hash.h
	clang -o example-hash example-hash.c src/hash.c -g -gdwarf-4

example-bstree: example-bstree.c src/bstree.c src/bstree.h
	clang -o example-bstree example-bstree.c src/bstree.c -g -gdwarf-4