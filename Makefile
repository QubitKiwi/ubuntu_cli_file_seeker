
a.out : main.o libmine.a
	gcc -o a.out main.o libmine.a

main.o : common.h main.c
	gcc -c -o main.o main.c

libmine.a : dir.o history.o kbhit.o
	ar rs libmine.a dir.o history.o kbhit.o

dir.o : common.h dir.c
	gcc -c -o dir.o dir.c

history.o : common.h history.c
	gcc -c -o history.o history.c

kbhit.o : common.h kbhit.c
	gcc -c -o kbhit.o kbhit.c

clean:
	rm *.o a.out