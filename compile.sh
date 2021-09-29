gcc -c dir.c kbhit.c time.c
ar rs libmine.a dir.o kbhit.o time.o
gcc -o movedir movedir.c libmine.a
