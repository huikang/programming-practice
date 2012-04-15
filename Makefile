CC=gcc

ALL:	gcd postfix bitree test sumTov strcmp searchWithEmpty reverseString edit_dist traverse_tree\
printPar reverseLinkedList pivot_binary_search

test:	test.o
	${CC} -o test test.o

test.o:	test.c
	${CC} -o test.o -c test.c


gcd:	gcd.o
	${CC} -o gcd gcd.o

gcd.o:	gcd.c
	${CC} -o gcd.o -c gcd.c


postfix:	postfix.o
	${CC} -o postfix postfix.o
postfix.o:	postfix.c
	${CC} -o postfix.o -c postfix.c

# Binary tree application
bitree: bitree.o
	${CC} -o bitree bitree.o
bitree.o:	bitree.c
	${CC} -o bitree.o -c bitree.c

sumTV: sumTov.o
	${CC} -o sumTov sumTo.o
sumTov.o:	sumTov.c
	${CC} -o sumTov.o -c sumTov.c
	
strcmp: strcmp.o
	${CC} -o strcmp strcmp.o
strcmp.o:	strcmp.c
	${CC} -o strcmp.o -c strcmp.c

searchWithEmpty: searchWithEmpty.o
	${CC} -o searchWithEmpty searchWithEmpty.o
searchWithEmpty.o:	searchWithEmpty.c
	${CC} -o searchWithEmpty.o -c searchWithEmpty.c

reverseString: reverseString.o
	${CC} -o reverseString reverseString.o
reverseString.o:	reverseString.c
	${CC} -o reverseString.o -c reverseString.c

edit_dist: edit_dist.o
	${CC} -o edit_dist edit_dist.o
edit_dist.o:	edit_dist.c
	${CC} -o edit_dist.o -c edit_dist.c

printPar: printPar.o
	${CC} -o printPar printPar.o
printPar.o:	printPar.c
	${CC} -o printPar.o -c printPar.c

reverseLinkedList: reverseLinkedList.o
	${CC} -o reverseLinkedList reverseLinkedList.o
reverseLinkedList.o:	reverseLinkedList.c
	${CC} -o reverseLinkedList.o -c reverseLinkedList.c

traverse_tree: traverse_tree.o tree.o
	${CC} -Wall -o traverse_tree traverse_tree.o tree.o

pivot_binary_search: pivot_binary_search.o
	${CC} -Wall -o pivot_binary_search pivot_binary_search.o

clean:
	rm *.o test postfix gcd bitree sumTov strcmp reverseString printPar \
  traverse_tree pivot_binary_search
