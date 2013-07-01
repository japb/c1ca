a.out:	main.c main.h search.o 
		gcc main.c search.o -Wall

search.o:	search.c
		gcc -c search.c
